#include "RecordStream.h"
#include "TimeUtils.h"

RecordStream::RecordStream(Encoder& encoder)
  : EncoderEngine(encoder)
{
}

void RecordStream::Handle(const unsigned char* data, unsigned size)
{
  Profile profile("Encode");
  EncoderEngine.Encode(data, size);
}
