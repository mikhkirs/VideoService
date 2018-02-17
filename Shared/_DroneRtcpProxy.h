#pragma once

#include <string>

class RtcpProxy
{
public:
  RtcpProxy();
  void CreateRtspListenSocket();
  void ConnectServer();

private:
  std::string ServerHostname;
  int ServerPort;
  int RtspListenSocket;
  int ServerSocket;
  sockaddr_in RtspListenAddr;
};