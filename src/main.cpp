/**
@file main.cpp
*/


/*! \mainpage Lab Book 3
 *
 * Implementation of a Double Linked List
 */

 // Define and includes to show memory leak report
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include "doubleLinkedList.h"

using namespace std;

void main() /** Entry point for the application */
{
	DoubleLinkedList<char> myLinkedList;

	myLinkedList.pushToBack('C'); //All push methods are being demonstrated to populate the list
	myLinkedList.pushBehindCurrent('D');
	myLinkedList.pushInFrontOfCurrent('B');
	myLinkedList.pushToBack('E');
	myLinkedList.pushToFront('A');
	myLinkedList.pushToBack('F');

	cout << "Printing List: " << endl;
	myLinkedList.printList(); // PRINT LIST
	cout << endl;

	
	// Remove the last element in the list
	
	cout << "Back node is: " << myLinkedList.getBack() << endl; //LOOK AT BACK ELEMENT IN LIST
	myLinkedList.popFromBack(); //POP FROM BACK OF LIST
	cout << "New back node is: " << myLinkedList.getBack() << endl << endl;

	
	// Remove the first element in the list
	
	cout << "Front node is: " << myLinkedList.getFront() << endl; //LOOK AT FRONT ELEMENT IN LIST
	myLinkedList.popFromFront(); //POP FROM FRONT OF LIST
	cout << "New front node is: " << myLinkedList.getFront() << endl << endl;

	
	//Traverse the current element forwards and backwards
	
	cout << "Current Node is: " << myLinkedList.getCurrent() << endl; //LOOK AT CURRENT ELEMENT IN LIST
	myLinkedList.traverseForwards(); //MOVE CURRENT POINTER FORWARDS IN LIST
	
	cout << "New Current Node is: " << myLinkedList.getCurrent() << endl;
	myLinkedList.traverseBackwards(); //MOVE CURRENT POINTER BACKWARDS IN LIST x2
	myLinkedList.traverseBackwards();
	
	cout << "New Current Node is: " << myLinkedList.getCurrent() << endl << endl;

	
	//Give the number of elements in the list
	
	cout << "List size is: " << myLinkedList.getSize() << endl;
	myLinkedList.pushInFrontOfCurrent('Z');
	cout << "List size after pushing is: " << myLinkedList.getSize() << endl << endl;

	
	while (!myLinkedList.isEmpty()) //Deleting list after use
	{
		cout << myLinkedList.popFromFront() << endl;
	}

	cout << endl;
	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}