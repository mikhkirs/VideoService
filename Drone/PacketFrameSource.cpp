#include "PacketFrameSource.h"
#include "InputFile.hh"
#include "GroupsockHelper.hh"
#include <iostream>

PacketFrameSource::PacketFrameSource(UsageEnvironment& env, Buffer& payloadBuffer)
  : FramedSource(env)
  , PayloadBuffer(payloadBuffer)
{
}

PacketFrameSource::~PacketFrameSource()
{
}

void PacketFrameSource::doGetNextFrame()
{
  while (PayloadBuffer.GetDataSize() < fMaxSize)
  {
    usleep(1);
  }

  memcpy(fTo, PayloadBuffer.GetData(), fMaxSize);
  fFrameSize = fMaxSize;
  PayloadBuffer.Consolidate(fMaxSize);

  gettimeofday(&fPresentationTime, NULL);
  nextTask() = envir().taskScheduler().scheduleDelayedTask(0,
    (TaskFunc*)FramedSource::afterGetting, this);
}

void PacketFrameSource::doStopGettingFrames() 
{
  envir().taskScheduler().unscheduleDelayedTask(nextTask());
}

