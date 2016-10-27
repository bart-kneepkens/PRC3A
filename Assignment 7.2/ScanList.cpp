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
    }
    
    Scan* previous = head;
    Scan* next = head->getNext();
    
    while(next != NULL){
        
        if(next->getSerialNumber() == serialNumber){
            next->recycle();
            return;
        }
        
        if((next->getSerialNumber() > serialNumber) && (serialNumber < previous->getSerialNumber())){
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

//bool ScanList::removeScan (int serialNumber){
//    Scan* toBeRemoved = getScanByNr(serialNumber);
//
//    if(toBeRemoved == NULL){
//        return false;
//    }
//
//    // If this scan is head, make sure to move the head forward.
//    if(toBeRemoved == head){
//        head = toBeRemoved->getNext();
//        delete toBeRemoved;
//        return true;
//    }
//
//    // Make sure that Scan h is the scan BEFORE the scan that needs to be deleted.
//    Scan* h = head;
//    while(h->getNext() != toBeRemoved && h != NULL){
//        h = h->getNext();
//    }
//
//    // Make sure the Scan h will point to the scan AFTER the deleted one.
//    if(h != NULL){
//        h->setNext(toBeRemoved->getNext());
//        delete toBeRemoved;
//        return true;
//    }
//
//    // Not found.
//    return false;
//}

//int ScanList::getTimesRecycled(int serialNumber){
//    Scan* scan = getScanByNr(serialNumber);
//
//    if(scan == NULL){
//        return 0;
//    }
//
//    return scan->getTimesRecycled();
//}

//void ScanList::addScan (int serialNumber){
//
//    // If the list is empty, just add a new Scan.
//    if (head == NULL)
//    {
//        head = new Scan(serialNumber);
//        return;
//    }
//
//    Scan* scan = getScanByNr(serialNumber);
//
//    if(scan != NULL){
//        scan->recycle();
//        return;
//    }
//
//    scan = new Scan(serialNumber);
//
//    // If smaller serial than head, make it head
//    if(head->getSerialNumber() > serialNumber){
//        scan->setNext(head->getNext());
//        head->setNext(scan);
//        return;
//    }
//
//    Scan* previous = head;
//
//    // Make sure that Scan previous is the scan BEFORE the scan that needs to be added.
//    while(previous->getNext()->getSerialNumber() << scan->getSerialNumber()){
//        previous = previous->getNext();
//    }
//
//    // Insert after previous.
//    if(previous != NULL){
//        scan->setNext(previous->getNext());
//        previous->setNext(scan);
//    }
//
//}

