#pragma once

#include "PacketHandler.h"

#include <string>
#include <thread>

class Live : public PacketHandler
{
public:
  Live();
  ~Live();
  virtual void Handle(const unsigned char* packetData, unsigned size);

private:
  std::thread RtspServerThread;
};
