#pragma once

#include <memory>

using namespace std;

/*! \class Node
	\brief Nodes to be stored in the double linked list class
*/

template<class G>
class Node
{
private:
	G data; //!< Data to be stored in the node
	shared_ptr<Node<G>> next; //!< Pointer to the next node in the list
	shared_ptr<Node<G>> prev; //!< Pointer to the previous node in the list

public:
	Node(G newdata, shared_ptr<Node<G>> newNext, shared_ptr<Node<G>> newPrev); //!< Constructor that takes in data to be stored, pointer to the next node and a pointer to the previous node
	G getData(); //!< Returns stored data
	shared_ptr<Node<G>> getNext(); //!< Returns a pointer to the next node
	shared_ptr<Node<G>> getPrev(); //!< Returns a pointer to the previous node
	void setNext(shared_ptr<Node<G>> newNext); //!< Set the node's next node
	void setPrev(shared_ptr<Node<G>> newPrev); //!< Set the node's previous node
};

template<class G>
Node<G>::Node(G newData, shared_ptr<Node<G>> newNext, shared_ptr<Node<G>> newPrev)
{
	data = newData;
	next = newNext;
	prev = newPrev;
}

template<class G>
G Node<G>::getData()
{
	return data;
}

template<class G>
shared_ptr<Node<G>> Node<G>::getNext()
{
	return next;
}

template<class G>
shared_ptr<Node<G>> Node<G>::getPrev()
{
	return prev;
}

template<class G>
void Node<G>::setNext(shared_ptr<Node<G>> newNext)
{
	next = newNext;
}

template<class G>
void Node<G>::setPrev(shared_ptr<Node<G>> newPrev)
{
	prev = newPrev;
}
