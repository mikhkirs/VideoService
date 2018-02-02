#include "FileWriter.h"
#include "LiveStream.h"
#include "RaspberryCamera.h"
#include "RaspberryEncoder.h"
#include "RecordStream.h"

#include <iostream>

int main(int argc, char **argv) 
{
  try
  {
    FileWriter fileWriter("out.h264");
    FileWriter liveFileWriter("live.h264");
    RaspberryEncoder recordEncoder(1280, 960, 1000, 25, fileWriter);
    RaspberryEncoder liveEncoder(1280, 960, 500, 25, liveFileWriter);

    auto recordStream = std::make_shared<RecordStream>(recordEncoder);
    auto liveStream = std::make_shared<LiveStream>(liveEncoder);
    
    RaspberryCamera camera(1280, 960, 25);
    camera.AddHandler(recordStream);
    camera.AddHandler(liveStream);
    camera.Capture();
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

