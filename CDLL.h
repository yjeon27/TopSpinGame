#pragma once
#include <iostream>


template <class Item>
class LinkedList{
private:
	class Node {
	public:
		Item value;
		Node *next;
		Node *prev;
		Node(Item val, Node *nx = NULL, Node *pre = NULL) :value(val), next(nx), prev(pre) {}
	};
	Node *m_head = NULL;
	Node *m_tail = NULL;
	unsigned int m_size;

public:
	//	constructor
	LinkedList();
	//	destructor
	~LinkedList();
	//	add a new node to the end of the linked list with value d
	void addData(Item);
	//	advance head to next node
	void incrementHead();
	//	move head to previous node
	void decrementHead();
	//	swap the data in the 2 nodes
	void swap(unsigned int, unsigned int);
	//	return the data associated in the i-th node of the list
	Item getData(unsigned int i)const;
};

//	CONSTRUCTOR
template <class Item>
LinkedList<Item>::LinkedList() :m_head(NULL), m_tail(NULL), m_size(0) {}

//	DESTRUCTOR - deep scan/delete all existing nodes
template <class Item>
LinkedList<Item>::~LinkedList() {
	Node *here = m_head;
	Node *nxt = NULL;
	for (int k(1); k <= m_size; k++) {
		nxt = here->next;
		delete here;
		here = nxt;
	}
}

//	DONE - add a new node to the end of the linked list with value d
template<class Item>
void LinkedList<Item>::addData(Item d) {
	//	if in the case where the list is empty, creating a new node for the very first time
	if (m_head == NULL || m_tail == NULL) {
			m_head = m_tail = new Node(d);
			m_size++;
	}
	//	all other cases when there is a pre-existing node, you are adding a new node to the tail
	else {
		Node *oldTail = m_tail;
		m_head->prev = m_tail = m_tail->next = new Node(d, m_head, oldTail);
		m_size++;
	}
}

//	DONE - advance head to next node
template <class Item>
void LinkedList<Item>::incrementHead() {
	m_head = m_head->next;
	m_tail = m_tail->next;
}

//	DONE - move head to previous node
template <class Item>
void LinkedList<Item>::decrementHead() {
	m_head = m_head->prev;
	m_tail = m_tail->prev;
}

//	DONE - swap the data in the 2 nodes (the source and the destination)
template <class Item>
void LinkedList<Item>::swap(unsigned int src, unsigned int dst) {
	Node *first = m_head;
	Node *second = m_head;
	//	traverse the list so node ptr first points to the src element
	for (int k(1); k < src; k++) {
		first = first->next;
	}
	//	traverse the list so node ptr second points to the dst element
	for (int k(1); k < dst; k++) {
		second = second->next;
	}
	//	first and second node pointers swap and points to its counterpart's node
	Item temp = first->value;
	first->value = second->value;
	second->value = temp;
}

//	DONE - return the data associated in the i-th node of the list
template <class Item>
Item LinkedList<Item>::getData(unsigned int i)const {
	Node *here = m_head;
	//	traverse the list so node ptr here points to the correct node index
	for (int k(0); k < i-1; k++) {
		here = here->next;
	}
	//	store value that's held inside the specified node to another variable of same template type (Item) and return the value
	Item hold = here->value;
	return hold;
}