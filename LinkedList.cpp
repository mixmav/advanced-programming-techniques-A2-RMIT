#include "LinkedList.h"

LinkedList<class T>::LinkedList()
{
	
}

LinkedList<class T>::~LinkedList()
{
	for (Node* i = head; i != nullptr; )
	{
		Node* nextNode = i->next;
		delete i;
		i = nextNode;
	}
}

bool LinkedList<class T>::contains(T* item)
{
	for (Node* i = head; i != nullptr; i = i->next)
		if (item == i->data)
			return true;

	return false;
}

int LinkedList<class T>::find(T* item) 
{
	int counter = 0;
	for (Node* i = head; i != nullptr; i = i->next)
	{
		if (item == i->data)
			return counter;
		else
			counter++;
	}
			
	return -1;
}

int LinkedList<class T>::size()
{
	return this->length;
}

void LinkedList<class T>::push_back(T* item)
{
	if (head == nullptr)
		tail = head = new Node(item, nullptr, nullptr);
	else
		tail = tail->next = new Node(item, tail, nullptr);

	length++;
}

T* LinkedList<class T>::at(int index)
{
	Node* n = head;
	for (int i = 0; i < index && n != nullptr; i++, n = n->next) ;
	if (n == nullptr)
		throw -1;

	return n->data;
}

void LinkedList<class T>::insert(T* item, int index)
{
	if (index == 0)
	{
		Node* newNode = new Node(item, nullptr, head);
		if (head != nullptr)
			head->last = newNode;
		head = newNode;
	}
	else
	{
		Node* n = head;
		for (int i = 0; i < index - 1 && n != nullptr; i++, n = n->next);
		if (n == nullptr)
			throw -1;

		Node* newNode = new Node(item, n, n->next);
		if (n->next != nullptr)
			n->next->last = newNode;
		n->next = newNode;
	}
	length++;
}

void LinkedList<class T>::remove(T* item)
{
	for (Node* i = head; i != nullptr; i = i->next)
		if (item == i->data)
			delete i;

	length--;
}

void LinkedList<class T>::removeAt(int index)
{
	Node* n = head;
	for (int i = 0; i < index && n != nullptr; i++, n = n->next);
	if (n == nullptr)
		throw - 1;

	delete n;
	length--;
}

template<> LinkedList<T>::Node::Node(T* item, Node* last, Node* next)
{
	this->data = item;
	this->last = last;
	this->next = next;
}

template<> LinkedList<T>::Node::~Node()
{
	if (next != nullptr)
		next->last = last;

	if (last != nullptr)
		last->next = next;

	last = next = nullptr;
	data = nullptr;
}

template<> LinkedList<T>::Iterator::Iterator(Node* node)
{
	this->node = node;
}

template<> LinkedList<T>::Iterator::~Iterator()
{
	node = nullptr;
}

template<> T* LinkedList<T>::Iterator::get()
{
	return node->data;
}

template<> T* LinkedList<T>::Iterator::next()
{	
	if (!hasNext())
		return nullptr;
	node = node->next;
	return node->data;
}

template<> T* LinkedList<T>::Iterator::last()
{
	if (!hasLast())
		return nullptr;
	node = node->last;
	return node->data;
}

template<> bool LinkedList<T>::Iterator::hasNext()
{
	return node->next != nullptr;
}

template<> bool LinkedList<T>::Iterator::hasLast()
{
	return node->last != nullptr;
}

LinkedList<T>::Iterator LinkedList<T>::begin()
{
	return Iterator(head);
}

LinkedList<T>::Iterator LinkedList<T>::end()
{
	return Iterator(tail);
}

T** LinkedList<T>::toArray()
{
	T** arr = new T*[length];
	int i = 0;
	for (Node* n = head; n != nullptr; n = n->next, i++)
		arr[i] = n->data;
	return arr;
}