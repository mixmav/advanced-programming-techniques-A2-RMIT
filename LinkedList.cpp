#include "LinkedList.h"

template<class T> LinkedList<T>::LinkedList()
{
	
}

template<class T> LinkedList<T>::~LinkedList()
{
	for (Node* i = head; i != nullptr; )
	{
		Node* nextNode = i->next;
		delete i;
		i = nextNode;
	}
}

template<class T> bool LinkedList<T>::contains(T* item)
{
	for (Node* i = head; i != nullptr; i = i->next)
		if (item == i->data)
			return true;

	return false;
}

template<class T> int LinkedList<T>::find(T* item) 
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

template<class T> int LinkedList<T>::size()
{
	return this->length;
}

template<class T> void LinkedList<T>::push_back(T* item)
{
	if (head == nullptr)
		tail = head = new Node(item, nullptr, nullptr);
	else
		tail = tail->next = new Node(item, tail, nullptr);

	length++;
}

template<class T> T* LinkedList<T>::at(int index)
{
	Node* n = head;
	for (int i = 0; i < index && n != nullptr; i++, n = n->next) ;
	if (n == nullptr)
		throw -1;

	return n->data;
}

template<class T> void LinkedList<T>::insert(T* item, int index)
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

template<class T> void LinkedList<T>::remove(T* item)
{
	for (Node* i = head; i != nullptr; i = i->next)
		if (item == i->data)
			delete i;

	length--;
}

template<class T> void LinkedList<T>::removeAt(int index)
{
	Node* n = head;
	for (int i = 0; i < index && n != nullptr; i++, n = n->next);
	if (n == nullptr)
		throw - 1;

	delete n;
	length--;
}

template<class T> LinkedList<T>::Node::Node(T* item, Node* last, Node* next)
{
	this->data = item;
	this->last = last;
	this->next = next;
}

template<class T> LinkedList<T>::Node::~Node()
{
	if (next != nullptr)
		next->last = last;

	if (last != nullptr)
		last->next = next;

	last = next = nullptr;
	data = nullptr;
}

template<class T> LinkedList<T>::Iterator::Iterator(Node* node)
{
	this->node = node;
}

template<class T> LinkedList<T>::Iterator::~Iterator()
{
	node = nullptr;
}

template<class T> T* LinkedList<T>::Iterator::get()
{
	return node->data;
}

template<class T> T* LinkedList<T>::Iterator::next()
{	
	if (!hasNext())
		return nullptr;
	node = node->next;
	return node->data;
}

template<class T> T* LinkedList<T>::Iterator::last()
{
	if (!hasLast())
		return nullptr;
	node = node->last;
	return node->data;
}

template<class T> bool LinkedList<T>::Iterator::hasNext()
{
	return node->next != nullptr;
}

template<class T> bool LinkedList<T>::Iterator::hasLast()
{
	return node->last != nullptr;
}

template<class T> typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
	return Iterator(head);
}

template<class T> typename LinkedList<T>::Iterator LinkedList<T>::end()
{
	return Iterator(tail);
}

template<class T> T** LinkedList<T>::toArray()
{
	T** arr = new T*[length];
	int i = 0;
	for (Node* n = head; n != nullptr; n = n->next, i++)
		arr[i] = n->data;
	return arr;
}