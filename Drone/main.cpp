#include "Config.h"
#include "FileWriter.h"
#include "LiveSender.h"
#include "LiveStream.h"
#include "RaspberryCamera.h"
#include "RaspberryEncoder.h"
#include "RecordStream.h"
#include "WebServer.h"

#include <iostream>

int main(int argc, char **argv) 
{
  try
  {
    Config config;

    bool recordStarted = config.GetInt("record", "started") == 1;
    std::string recordPath = config.GetString("record", "path");
    int width = config.GetInt("record", "width");
    int height = config.GetInt("record", "height");
    int bitrate = config.GetInt("record", "bitrate");
    int fps = config.GetInt("record", "fps");
    int clipTime = config.GetInt("record", "clip_time");
    int clipLimit = config.GetInt("record", "clip_limit");

    int liveWidth = config.GetInt("live", "width");
    int liveHeight = config.GetInt("live", "height");
    int liveBitrate = config.GetInt("live", "bitrate");

    int httpServerPort = config.GetInt("common", "http_server_port");

    FileWriter fileWriter(recordPath, clipTime, clipLimit);
    LiveSender liveSender;
    RaspberryEncoder recordEncoder(width, height, bitrate, fps, fileWriter);
    RaspberryEncoder liveEncoder(liveWidth, liveHeight, liveBitrate, fps, liveSender);

    auto recordStream = std::make_shared<RecordStream>(recordEncoder, recordStarted);
    auto liveStream = std::make_shared<LiveStream>(liveEncoder);

    RaspberryCamera camera(width, height, fps);
    camera.AddHandler(recordStream);
    camera.AddHandler(liveStream);
    camera.Capture();

    WebServer webServer(httpServerPort, *recordStream, *liveStream);
    webServer.Run();
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

