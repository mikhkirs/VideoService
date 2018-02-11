#pragma once

#include "H264VideoFileServerMediaSubsession.hh"

class H264Subsession : public H264VideoFileServerMediaSubsession
{
public:
  H264Subsession(UsageEnvironment& env);

  virtual FramedSource* createNewStreamSource(unsigned clientSessionId, unsigned& estBitrate);
};
