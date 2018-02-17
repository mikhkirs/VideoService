#include "RtcpProxy.h"

RtcpProxy::RtcpProxy()
  : ServerHostname("78.155.199.72")
  , ServerPort(10001)
  , ListenServerSocket(-1)
  , ServerSocket(-1)
{

}

void RtcpProxy::CreateRtspListenSocket()
{
  memset(&RtspListenAddr, 0, sizeof(RtspListenAddr));
  RtspListenAddr.sin_family = AF_INET;
  RtspListenAddr.sin_addr.s_addr = INADDR_ANY;
  RtspListenAddr.sin_port = htons(8554);

  RtspListenSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (RtspListenSocket < 0)
  {
    throw std::runtime_error("Failed to create socket");
  }

  if (bind(RtspListenSocket, reinterpret_cast<sockaddr*>(&RtspListenAddr), sizeof(RtspListenAddr)) < 0)
  {
    throw std::runtime_error("Failed to bind socket");
  }

  if (bind(ListenServerSocket, reinterpret_cast<sockaddr*>(&RtspListenAddr), sizeof(RtspListenAddr)) < 0)
  {
    throw std::runtime_error("Failed to bind socket");
  }
}

void RtcpProxy::Connect()
{
    return 1;
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);

}