#include "H264Subsession.h"
#include "PacketFrameSource.h"

#include "H264VideoStreamFramer.hh"

H264Subsession::H264Subsession(UsageEnvironment& env)
  : H264VideoFileServerMediaSubsession(env, "", True)
{
}

FramedSource* H264Subsession::createNewStreamSource(unsigned clientSessionId, unsigned& estBitrate)
{
  auto h264 = new PacketFrameSource(envir());
  return H264VideoStreamFramer::createNew(envir(), h264);
}
