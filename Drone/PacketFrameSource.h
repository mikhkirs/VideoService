#pragma once

#include "FramedFileSource.hh"

class PacketFrameSource : public FramedSource
{
public:
  PacketFrameSource(UsageEnvironment& env);

  virtual ~PacketFrameSource();

private:
  virtual void doGetNextFrame();
  virtual void doStopGettingFrames();
};