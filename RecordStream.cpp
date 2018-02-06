#include "RecordStream.h"
#include "TimeUtils.h"

RecordStream::RecordStream(Encoder& encoder)
  : EncoderEngine(encoder)
  , Started(false)
{
}

void RecordStream::Handle(const unsigned char* data, unsigned size)
{
  if (Started)
  {
    Profile profile("Encode");
    EncoderEngine.Encode(data, size);
  }
}

void RecordStream::StartRecord()
{
  Started = true;
}

void RecordStream::StopRecord()
{
  Started = false;
}
