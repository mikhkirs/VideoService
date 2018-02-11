#include "LockedBuffer.h"
#include "MutexHolder.h"

LockedBuffer::LockedBuffer(unsigned size, const unsigned char* data)
  : Buffer(size, data)
{
}

void LockedBuffer::Add(const unsigned char* data, unsigned size)
{
  MutexHolder holder(Mutex);
  Buffer::Add(data, size);
}

void LockedBuffer::Reset()
{
  MutexHolder holder(Mutex);
  Buffer::Reset();
}

unsigned char* LockedBuffer::GetData()
{
  MutexHolder holder(Mutex);
  Buffer::GetData();
}

unsigned LockedBuffer::GetDataSize()
{
  MutexHolder holder(Mutex);
  Buffer::GetDataSize();
}

unsigned LockedBuffer::GetSize()
{
  MutexHolder holder(Mutex);
  Buffer::GetSize();
}

void LockedBuffer::Consolidate(unsigned offset)
{
  MutexHolder holder(Mutex);
  Buffer::Consolidate(offset);
}