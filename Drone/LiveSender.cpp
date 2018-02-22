#include "LiveSender.h"

#include <iostream>
#include <vector>
#include <string.h>

const unsigned RtpPacketSize = 15000;

LiveSender::LiveSender(const std::string& host, unsigned port)
  : PacketCount(0)
  , Socket(host, port)
{
  Socket.Connect();
}

LiveSender::~LiveSender()
{
}

void LiveSender::InitHeader(const unsigned char* packetData, unsigned size)
{
  Header.resize(size);
  memcpy(&Header[0], packetData, size);
}

void LiveSender::Handle(const unsigned char* packetData, unsigned size)
{
  std::vector<unsigned char> buffer(size + sizeof(PacketCount));
  memcpy(&buffer[0], &PacketCount, sizeof(PacketCount));
  memcpy(&buffer[sizeof(PacketCount)], packetData, size);
  Socket.Send(&buffer[0], buffer.size());
  ++PacketCount;
}

std::string LiveSender::GetHost() const
{
  return Socket.GetHost();
}

unsigned LiveSender::GetPort() const
{
  return Socket.GetPort();
}