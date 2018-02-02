#pragma once

#include "Encoder.h"
#include "FrameHandler.h"

class LiveStream : public FrameHandler
{
public:
  LiveStream(Encoder& encoder);
  virtual void Handle(const unsigned char* data, unsigned size);
};
