#include <cstddef> // needed for definition of NULL
#include <iostream>
#include "ScanList.h"

ScanList::ScanList(){
    head = NULL;
}

ScanList::~ScanList(){
    while(head != NULL){
        Scan* temp = head;
        head = head->getNext();
        delete temp;
        temp = NULL;
    }
}

void ScanList::addScan (int serialNumber){
    
    // If the list is empty, just add a new Scan.
    if (head == NULL){
        head = new Scan(serialNumber);
        return;
    }
    
    if (head->getSerialNumber() == serialNumber){
        head->recycle();
        return;
    }
    
    if(head->getSerialNumber() > serialNumber){
        Scan * temp = head;
        head = new Scan(serialNumber);
        head->setNext(temp);
        return;
    }
    
    Scan* previous = head;
    Scan* next = head->getNext();
    
    while(next != NULL){
        
        if(next->getSerialNumber() == serialNumber){
            next->recycle();
            return;
        }
        
        if((next->getSerialNumber() > serialNumber) && (serialNumber > previous->getSerialNumber())){
            Scan* toAdd = new Scan(serialNumber);
            previous->setNext(toAdd);
            toAdd->setNext(next);
            return;
        }
        
        previous = next;
        next = next->getNext();
    }

    // There hasn't been found a suitable place for this Scan
    // Place it at the end.
    previous->setNext(new Scan(serialNumber));
}

Scan* ScanList::getScanByNr(int position){
    if(position < 0 || head == NULL){
        return NULL;
    }
    
    Scan* h = head;
    int i = 0;
    
    while(i < position && h != NULL){
        i++;
        h = h->getNext();
    }
    return h;
}

bool ScanList::removeScan (int serialNumber){
    
    // If there is no list, return immediately.
    if(head == NULL){
        return false;
    }
    
    // If the head needs to be removed, do it immediately.
    if(head->getSerialNumber() == serialNumber){
        Scan* temp = head->getNext();
        delete head;
        head = temp;
        return true;
    }
    
    Scan* previous = head;
    Scan* next = head->getNext();
    
    while(next != NULL){
        if(next->getSerialNumber() == serialNumber){
            previous->setNext(next->getNext());
            delete previous;
            return true;
        }
        
        previous = next;
        next = next->getNext();
    }
    
    // A scan with this serialNumber has not been found.
    return false;
}

int ScanList::getTimesRecycled(int serialNumber){
    if(head == NULL){
        return 0;
    }
    
    Scan* scan = head;
    
    while(scan != NULL){
        if(scan->getSerialNumber() == serialNumber){
            return scan->getTimesRecycled();
        }
        scan = scan->getNext();
    }
    
    return 0;
}
