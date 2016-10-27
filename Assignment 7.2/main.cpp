/*
 *  main.cpp
 *
 *  Created on: Sep 25, 2013
 *  Author: P. Lambooij
 */

#include <string>
#include <iostream>

#include "ScanList.h"
#include "Scan.h"

int main()
{
  std::cout << "Illustration Linked List Operations\n";
    
    
    ScanList* scanList = new ScanList();
    
    scanList->addScan(100);

    scanList->show();
    
    scanList->addScan(200);
    
    scanList->show();

//  newNode = new Node(10);
//  MyNodeList->insertBefore(newNode, NULL);
//  MyNodeList->show();
//
//  newNode = new Node(20);
//  position = MyNodeList->getNodeByNr(0);
//  MyNodeList->insertAfter(newNode, position);
//  MyNodeList->show();
//
//  newNode = new Node(30);
//  position = MyNodeList->getNodeByNr(1);
//  MyNodeList->insertBefore(newNode, position);
//  MyNodeList->show();
//
//  newNode = new Node(40);
//  position = MyNodeList->getNodeByNr(2);
//  MyNodeList->insertAfter(newNode, position);
//  MyNodeList->show();
//
//  position = MyNodeList->getNodeByNr(1);
//  MyNodeList->removeNode(position);
//  MyNodeList->show();
//
//  std::cout << "\ndeleting NodeList";
//  delete MyNodeList;
//  std::cout << std::endl;
}
