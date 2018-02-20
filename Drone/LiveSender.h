#pragma once

#include "PacketHandler.h"
#include "UdpSendSocket.h"

#include <vector>

class LiveSender : public PacketHandler
{
public:
  LiveSender();
  ~LiveSender();
  virtual void InitHeader(const unsigned char* packetData, unsigned size);
  virtual void Handle(const unsigned char* packetData, unsigned size);

private:
  UdpSendSocket Socket;
  unsigned PacketCount;
  std::vector<unsigned char> Header;
};
