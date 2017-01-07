#include <string>
#include <iostream>
#include <cstdlib>

#include "SortedLinkedList.hpp"

int main()
{
    //SortedLinkedList<int*> list = SortedLinkedList<int*>();
    //int* dicks = new int(5);
    //list.Add(dicks);


    SortedLinkedList<int> list = SortedLinkedList<int>();
    //std::cout << "Count: " << list.Count() << std::endl;
    //std::cout << "-----" << list.Count() << std::endl;
    srand (time(NULL));

    //list.Add(rand() % 100);
    //list.Add(rand() % 100);
    //list.Add(rand() % 100);
    //list.Add(rand() % 100);
    list.Add(3);
    list.Add(9);
    list.Add(2);
    list.Add(1);
    list.RemoveAt(0);
    list.RemoveAt(0);
    list.RemoveAt(0);
    list.RemoveAt(0);
    std::cout << "Count: " << list.Count() << std::endl;

    list.Iterate();
    while (list.HasNext()) {
        std::cout << list.Next() << std::endl;
    }

    //std::cout << "At index 0: " << list.AtIndex(0) << std::endl;
    //std::cout << "At index 1: " << list.AtIndex(1) << std::endl;
    //std::cout << "At index 2: " << list.AtIndex(2) << std::endl;
}
