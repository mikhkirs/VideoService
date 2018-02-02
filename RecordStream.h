#pragma once

#include "Encoder.h"
#include "FrameHandler.h"

class RecordStream : public FrameHandler
{
public:
  RecordStream(Encoder& encoder);

  virtual void Handle(const unsigned char* data, unsigned size);

private:
  Encoder& EncoderEngine;
};
