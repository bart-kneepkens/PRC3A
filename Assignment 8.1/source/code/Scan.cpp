#include "Scan.h"

Scan::Scan(int number)
{
  serialNumber = number;
  timesRecycled = 0;
  next = 0;
}

Scan::~Scan()
{
}

int Scan::getSerialNumber() const
{
  return serialNumber;
}

Scan * Scan::getNext()
{
  return next;
}

void Scan::setNext(Scan * nextScan)
{
  next = nextScan;
}

void Scan::recycle()
{
  timesRecycled++;
}

int Scan::getTimesRecycled() const
{
  return timesRecycled;
}
