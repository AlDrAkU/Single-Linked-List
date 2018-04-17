#include "LinkedList.h"
#include <string>
LinkedList::LinkedList()
{
}

LinkedList::~LinkedList()
{
	Node* current = m_pFirstNode;
	while (current != NULL) {
	
		Node* next = current->pNext;
		delete current;
		current = next;

	}
	m_pFirstNode = NULL;
}

LinkedList::LinkedList( const LinkedList& other )
{
}

LinkedList& LinkedList::operator=( const LinkedList& other )
{
	return *this;
}

LinkedList::LinkedList( LinkedList&& other )
{
}

LinkedList& LinkedList::operator=(  LinkedList&& other )
{
	return *this;
}

// Create a node and add it at the start
void LinkedList::PushFront( int  value )
{
	m_Size++;
	Node *newNode = new Node(value);

	newNode->pNext = NULL;
	newNode->value = value;

	newNode->pNext = m_pFirstNode;
	m_pFirstNode = newNode;
}

// Remove and delete first Node
void LinkedList::PopFront( )
{
	if (m_pFirstNode != NULL)
	{
		Node* tmp = m_pFirstNode->pNext;
		delete m_pFirstNode;
		m_pFirstNode = tmp;
		--m_Size;

	}
}

// Remove all Nodes having this value
void LinkedList::Remove(int value)
{
	Node *currNode = new Node(value);
	Node *prevNode = new Node(value);

	currNode = m_pFirstNode;
	prevNode = m_pFirstNode;

	if (m_pFirstNode->value == value)
	{
		PopFront();

	}
	else
	{


		while (currNode != NULL)
		{

			if (currNode->value == value)
			{
				prevNode->pNext = currNode->pNext;
				delete currNode;

			}
			currNode = currNode->pNext;
			prevNode = prevNode->pNext;

		}


	}

}

// Create Node and insert after specified Node cur
void LinkedList::InsertAfter( Node* pBefore, int value )
{
	m_Size++;
	Node *newNode = new Node(value);
	newNode->value = value;
	newNode->pNext = pBefore->pNext;
	pBefore->pNext = newNode;
	
}

// Return pointer to first Node
Node* LinkedList::Begin( ) const
{
	return m_pFirstNode;
}

// Return number of Node objects in the list
size_t LinkedList::Size( ) const
{
	return m_Size;
}

// Send the values of the list to the out object, use a space as element separator
std::ostream& operator<<( std::ostream& out, const LinkedList& list )
{
	/*LinkedList list2 = list;*/

	Node *ptrCurrent = list.Begin();


	while (ptrCurrent !=NULL)
	{
		out << ptrCurrent->value<< " ";
		ptrCurrent = ptrCurrent->pNext;
		
	} 
	return out;
		

	

}
