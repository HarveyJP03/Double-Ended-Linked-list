#pragma once
#include "node.h"


using namespace std;

/*! \class Double Linked List
    \brief A double linked list data structure.
*/

template<class G>
class DoubleLinkedList
{
private:
    int size; //!< Size value of list
    shared_ptr<Node<G>> front; //!< Points to the front of the list
    shared_ptr<Node<G>> back; //!< Points to the back of the list
    shared_ptr<Node<G>> current; //!< Points to the current node of the list

public:
    DoubleLinkedList(); //!< Default Constructor
    void pushToFront(G newElement); //!< Pushes parameter new element to the front of the list
    void pushToBack(G newelement); //!< Pushes parameter new element to the back of the list
    void pushInFrontOfCurrent(G newelement); //!< Pushes parameter new element in front of the current node
    void pushBehindCurrent(G newelement); //!< Pushes parameter new element behind the current node
    G popFromFront(); //!< Deletes the front node from the list
    G popFromBack(); //!< Deletes the back node from the list
    G popCurrent(); //!< Deletes the current node from the list
    void traverseForwards(); //!< Moves the current pointer to current's next node
    void traverseBackwards(); //!< Moves the current pointer to current's previous node
    G getCurrent(); //!< Returns the data in the current node
    G getFront(); //!< Returns the data in the front node
    G getBack(); //!< Returns the data in the back node
    int getSize(); //!< Returns the size of the list
    bool isEmpty(); //!< Returns if the list is empty
    void printList();
};

template<class G>
DoubleLinkedList<G>::DoubleLinkedList()
{
    front = nullptr;
    back = nullptr;
    current = nullptr;
    size = 0;
}

template<class G>
void DoubleLinkedList<G>::pushToFront(G newElement)
{
    if (size == 0)
    {
        current = shared_ptr<Node<G>>(new Node<G>(newElement, front, back)); //first node to be added, previous and next nodes point to null
        front = current; //front pointer poiting to only node in list
        back = current; //back pointer pointing to only node in list 
        size++;
    }
    else
    {
        front = shared_ptr<Node<G>>(new Node<G>(newElement, nullptr, front)); //next is null, previous is current front
        front->getPrev()->setNext(front); //set the old fronts next to the new front (from nullptr)
        size++;
    }
}

template<class G>
void DoubleLinkedList<G>::pushToBack(G newElement)
{
    if (size == 0)
    {
        current = shared_ptr<Node<G>>(new Node<G>(newElement, nullptr, nullptr)); //first node to be added, previous and next nodes point to null
        front = current; //front pointer poiting to only node in list
        back = current; //back pointer pointing to only node in list 
        size++;
    }
    else
    {
        back = shared_ptr<Node<G>>(new Node<G>(newElement, back, nullptr)); //next is previous back, prev is null
        back->getNext()->setPrev(back); //set the old backs previous to the new back (from nullptr)
        size++;
    }
}

template<class G>
void DoubleLinkedList<G>::pushInFrontOfCurrent(G newElement)
{
    if (current == front)
    {
        pushToFront(newElement);
    }
    else
    {
        shared_ptr<Node<G>> tempNext = current->getNext(); //store current's next in temp next
        shared_ptr<Node<G>> newNode = shared_ptr<Node<G>>(new Node<G>(newElement, tempNext, current)); //next node is current's next, previous node is the current node
        current->setNext(newNode); //current's new next is new node
        newNode->getNext()->setPrev(newNode); //set the node next to current's next to the new node
        size++;
    }
}

template<class G>

void DoubleLinkedList<G>::pushBehindCurrent(G newElement)
{
    if (current == back)
    {
        pushToBack(newElement);
    }
    else
    {
        shared_ptr<Node<G>> tempPrev = current->getPrev(); //store current's prev is temp prev
        shared_ptr<Node<G>> newNode = shared_ptr<Node<G>>(new Node<G>(newElement, current, tempPrev)); //next node is current, previous node is current's previous node
        current->setPrev(newNode); //currents new prev is new node
        newNode->getPrev()->setNext(newNode); //set the node that used to be fore currents next to newNode
        size++;
    }
}

template<class G>
G DoubleLinkedList<G>::popFromFront()
{
    G poppedData = front->getData(); //to store popped data

    if (size == 1) //if last node in list
    {
        current = nullptr; //disconnect pointers from node
        back = nullptr;
        front = nullptr;
    }
    else
    {
        if (front == current) current = front->getPrev(); //if current is pointing at node to be deleted, move current
        shared_ptr<Node<G>> tempFront = front; //store front to be popped in tempFront
        front = tempFront->getPrev(); //new front is old front's previous node
        front->setNext(nullptr); //nothing in front of the new front, stop it from poitning to old front here
        tempFront->setNext(nullptr); //remove old fronts connection to list
        tempFront->setPrev(nullptr);
    }
    size--;
    return poppedData;
}

template<class G>
G DoubleLinkedList<G>::popFromBack()
{
    G poppedData = back->getData(); //to store popped data

    if (size == 1) //if last node in list
    {
        current = nullptr; //disconnect pointers from node
        back = nullptr;
        front = nullptr;
    }
    else //if there's still more nodes in the list
    {
        if (back == current) current = back->getNext(); //if current is pointing at node to be deleted, move current to next node
        shared_ptr<Node<G>> tempBack = back; //store back to be popped in tempBack
        back = tempBack->getNext(); //new back is the old backs next node
        back->setPrev(nullptr);
        tempBack->setNext(nullptr);
        tempBack->setNext(nullptr);
    }
    size--;
    return poppedData;
}

template<class G>
G DoubleLinkedList<G>::popCurrent()
{
    G poppedData = current->getData(); //store popped data

    if (current == front)
    {
        current = current->getPrev();
        popFromFront();
        return poppedData;
    }
    else if (current == back)
    {
        current = current->getNext();
        popFromBack();
        return poppedData;
    }
    else
    {
        current->getPrev()->setNext(current->getNext()); //set currents previous node's next node to currents next node
        current->getNext()->setPrev(current->getPrev()); //set currents next node's  previous node to current's previous node
        current = current->getNext();
        size--;
        return poppedData;
    }
}

template<class G>
void DoubleLinkedList<G>::traverseForwards()
{
    current = current->getNext();
}

template<class G>
void DoubleLinkedList<G>::traverseBackwards()
{
    current = current->getPrev();
}



template<class G>
G DoubleLinkedList<G>::getCurrent()
{
    return current->getData();
}

template<class G>
G DoubleLinkedList<G>::getFront()
{
    return front->getData();
}

template<class G>
G DoubleLinkedList<G>::getBack()
{
    return back->getData();
}

template<class G>
int DoubleLinkedList<G>::getSize()
{
    return size;
}

template<class G>
bool DoubleLinkedList<G>::isEmpty()
{
    if (size == 0) return true;
    return false;
}

template<class G>
void DoubleLinkedList<G>::printList()
{
    shared_ptr<Node<G>> iterator = front;

    for (int i = 0; i < size; i++)
    {
        cout << iterator->getData() << endl;
        iterator = iterator->getPrev();
    }
}