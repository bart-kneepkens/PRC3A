#include "ScanList.h"

ScanList::ScanList()
{
	head = 0;
}

ScanList::~ScanList()
{
  Scan* current = head;

  while (current != 0)
  {
    Scan* newCurrent = current->getNext();
    delete current;
    current = newCurrent;
  }
}

void ScanList::addScan(int serialNumber)
{
  // If the list is empty, just add a new Scan.
  if (head == 0)
  {
    head = new Scan(serialNumber);
    return;
  }

  // If the serialnumber equals head's, recycle.
  else if (head->getSerialNumber() == serialNumber)
  {
    head->recycle();
    return;
  }

  // Else if the item has to be placed before the head, do so.
  else if (head->getSerialNumber() > serialNumber)
  {
    Scan * newScan = new Scan(serialNumber);
    newScan->setNext(head);
    head = newScan;
    return;
  }

  // Else, iterate over the list.
  else
  {
    Scan * previous = head;
    Scan * current = head->getNext();

    while (current != 0)
    {
      // If the exact same serialnumber is found, just increment timesRecycled.
      if (current->getSerialNumber() == serialNumber)
      {
        current->recycle();
        return;
      }

      // Else if a higher serial number was found, insert inbetween previous and current.
      else if (current->getSerialNumber() > serialNumber)
      {
        Scan * newScan = new Scan(serialNumber);
        newScan->setNext(current);
        previous->setNext(newScan);
        return;
      }

      previous = current;
      current = current->getNext();
    }

    // If there was only head, or no existing serialnumber was found before which we can
    // insert the new serialnumber, then just append.
    previous->setNext(new Scan(serialNumber));
  }
}

Scan * ScanList::getScanByNr(int position)
{
  // If position is smaller than 0, return null.
  if (position < 0)
    return 0;

  // Iterate over Scans until position is found.
  Scan * current = head;
  int counter = 0;

  while (current != 0)
  {
    if (counter == position)
      return current;

    current = current->getNext();
    counter++;
  } 

  // If position was greater than number of items minus 1,
  // then return null.
  return 0;
}

bool ScanList::removeScan(int serialNumber)
{
  // If the list is empty, just return false.
  if (head == 0)
    return false;

  // Else if the head is the one we must remove, do so.
  else if (head->getSerialNumber() == serialNumber)
  {
    Scan * newHead = head->getNext();
    delete head;
    head = newHead;
    return true;
  }

  // Else, iterate over the list.
  else
  {
    Scan * previous = head;
    Scan * current = head->getNext();

    while (current != 0)
    {
      // If the serialnumber is found, then remove the scan.
      if (current->getSerialNumber() == serialNumber)
      {
        previous->setNext(current->getNext());
        delete current;
        return true;
      }

      previous = current;
      current = current->getNext();
    }
  }

  // If we failed to remove anything, return false.
  return false;
}

int ScanList::getTimesRecycled(int serialNumber)
{
  Scan * current = head;

  // Iterate over Scans to find the one with this serialnumber.
  while (current != 0)
  {
    if (current->getSerialNumber() == serialNumber)
      return current->getTimesRecycled();

    current = current->getNext();
  }

  // If no Scan with this serialnumber was found, just return 0.
  return 0;
}
