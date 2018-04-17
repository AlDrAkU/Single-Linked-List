#pragma once
#include <iostream>

struct Node
{
	Node( int value, Node *pNext = nullptr ) :value{ value }, pNext{ pNext } {}
	
	Node* pNext;
	int value;
};

class LinkedList
{
public:
	LinkedList( );
	~LinkedList( );
	LinkedList( const LinkedList& other );
	LinkedList& operator=( const LinkedList& other );
	LinkedList( LinkedList&& other );
	LinkedList& operator=(  LinkedList&& other );

	void PushFront( int  value );
	void PopFront( );
	void Remove( int value );
	void InsertAfter( Node* pBefore, int value );
	size_t Size( ) const;
	Node* Begin( ) const;

private: 
	Node* m_pFirstNode;
	size_t m_Size;

	// Your helper functions
};

std::ostream& operator<<( std::ostream& out, const LinkedList& list );
