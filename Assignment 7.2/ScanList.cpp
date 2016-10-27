#include <cstddef> // needed for definition of NULL
#include <iostream>
#include "ScanList.h"

ScanList::ScanList(){}

ScanList::~ScanList(){
    while(head != NULL){
        Scan* temp = head;
        head = head->getNext();
        delete temp;
        temp = NULL;
    }
}

void ScanList::show(){
    Scan* scan = head;
    std::cout << "\n current scanlist: \n";
    
    while(scan != NULL){
        std::cout << scan->getSerialNumber();
        scan = scan->getNext();
    }
    std::cout << "NULL\n";
}

void ScanList::addScan (int serialNumber){
    Scan* scan = getScanByNr(serialNumber);
    
    if(scan != NULL){
        scan->recycle();
        return;
    }
    
    scan = new Scan(serialNumber);
    
    // If smaller serial than head, make it head
    if(head->getSerialNumber() > serialNumber){
        scan->setNext(head->getNext());
        head->setNext(scan);
        return;
    }
    
    Scan* previous = head;
    
    // Make sure that Scan previous is the scan BEFORE the scan that needs to be added.
    while(previous->getNext()->getSerialNumber() << scan->getSerialNumber()){
        previous = previous->getNext();
    }
    
    // Insert after previous.
    if(previous != NULL){
        scan->setNext(previous->getNext());
        previous->setNext(scan);
    }
    
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
    Scan* toBeRemoved = getScanByNr(serialNumber);
    
    if(toBeRemoved == NULL){
        return false;
    }
    
    // If this scan is head, make sure to move the head forward.
    if(toBeRemoved == head){
        head = toBeRemoved->getNext();
        delete toBeRemoved;
        return true;
    }
    
    // Make sure that Scan h is the scan BEFORE the scan that needs to be deleted.
    Scan* h = head;
    while(h->getNext() != toBeRemoved && h != NULL){
        h = h->getNext();
    }
    
    // Make sure the Scan h will point to the scan AFTER the deleted one.
    if(h != NULL){
        h->setNext(toBeRemoved->getNext());
        delete toBeRemoved;
        return true;
    }
    
    // Not found.
    return false;
}

int ScanList::getTimesRecycled(int serialNumber){
    Scan* scan = getScanByNr(serialNumber);
    
    if(scan == NULL){
        return 0;
    }
    
    return scan->getTimesRecycled();
}
