#include "Stream.h"
#include "TimeUtils.h"

Stream::Stream(Encoder& encoder, unsigned width, unsigned height, unsigned fps, bool started)
  : EncoderEngine(encoder)
  , Width(width)
  , Height(height)
  , Fps(fps)
  , Started(started)
{
}

void Stream::Handle(const unsigned char* data, unsigned size)
{
  if (Started)
  {
    EncoderEngine.Encode(data, size);
  }
}

void Stream::Start()
{
  Started = true;
}

void Stream::Stop()
{
  Started = false;
}

bool Stream::IsStarted() const
{
  return Started;
}

unsigned Stream::GetWidth() const
{
  return Width;
}

unsigned Stream::GetHeight() const
{
  return Height;
}

unsigned Stream::GetFps() const
{
  return Fps;
}
