#include "PacketFrameSource.h"
#include "InputFile.hh"
#include "GroupsockHelper.hh"
#include <iostream>

PacketFrameSource::PacketFrameSource(UsageEnvironment& env)
: FramedSource(env)
{
}

PacketFrameSource::~PacketFrameSource()
{
}

void PacketFrameSource::doGetNextFrame()
{
  gettimeofday(&fPresentationTime, NULL);
  nextTask() = envir().taskScheduler().scheduleDelayedTask(0,
    (TaskFunc*)FramedSource::afterGetting, this);
}

void PacketFrameSource::doStopGettingFrames() 
{
  envir().taskScheduler().unscheduleDelayedTask(nextTask());
}

