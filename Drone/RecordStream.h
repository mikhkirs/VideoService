#pragma once

#include "Encoder.h"
#include "FrameHandler.h"
#include "StartController.h"

class RecordStream : public FrameHandler, public StartController
{
public:
  RecordStream(Encoder& encoder, bool started);

  virtual void Handle(const unsigned char* data, unsigned size);

  virtual void Start();
  virtual void Stop();
  virtual bool IsStarted() const;

private:
  Encoder& EncoderEngine;
  bool Started;
};
