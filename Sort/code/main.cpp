#include <iostream>
//#include <cstddef> // needed for definition of NULL

#include "FileStructure.h"

void split(File * source, File ** front, File ** back){
    File* fast;
    File* slow;
    
    if(source == NULL || source->getNext() == NULL){
        *front = source;
        *back = NULL;
    } else {
        slow = source;
        fast = source->getNext();
        
        while (fast != NULL){
            fast = fast->getNext();
            if(fast != NULL){
                slow = slow->getNext();
                fast = fast->getNext();
            }
        }
        
        *front = source;
        *back = slow->getNext();
        slow->setNext(NULL);
    }
}

File* sorted(File* a, File* b){
    File* result = NULL;
    
    if(a == NULL)
        return(b);
    else if(b == NULL)
        return(a);
    
    if(a->getName().compare(b->getName())){
        result = a;
        result->setNext(sorted(a->getNext(), b));
    } else {
        result = b;
        result->setNext(sorted(a, b->getNext()));
    }
    return result;
}


void mergeSort(File** headref){
    File * head = *headref;
    
    File * a;
    File * b;
    
    split(head, &a, &b);
    
    mergeSort(&a);
    mergeSort(&b);
    
    *headref = sorted(a,b);
}


int main()
{
    FileStructure f;
    Dir head;
    
    f.loadFile("data/gibberish.bin", head);

    // next line is only to show what kind of data we're working with
    // remove this line to increase performance!
    
    
    // sort all data
    // todo: your code here!
    
    
    // sort dirs
    
    
    // sort files
    File* headFile = head.getFirstFile();
    
    mergeSort(&headFile);

    //std::cout << head.toString(false);

    // save sorted data into a new file called sorted.bin
    f.saveFile(head, "sorted.bin");

    return 0;
}
