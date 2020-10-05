#ifndef LLARRAY_HEADER
#define LLARRAY_HEADER

template <class T> class LinkedList
{
	class Node
	{
		friend class LinkedList;
		friend class Iterator;

		// Create a new instance of Node using data, last node, and next node, specify nullptr if none.
		Node(T* data, Node* last, Node* next);

		// Destructs Node and attaches nodes around it to keep the chain intact.
		~Node();

		T* data = nullptr;
		Node *next = nullptr, *last = nullptr;
	};

	public:
		class Iterator
		{	
			friend class LinkedList;

			private: 
				Node* node = nullptr;
				Iterator(Node* node);

			public:
				~Iterator();

				// Moves to the next element and returns its value.
				T* next();

				// Moves to the last element and returns its value.
				T* last();

				// Determines whether an element exists after this one.
				// Can detect the end of the list.
				bool hasNext();

				// Determines whether an element exists before this one.
				// Can detect the beginning of the list.
				bool hasLast();

				// Gets the value of the current element pointing at.
				T* get();
		};

		LinkedList();
		~LinkedList();

		// Determines whether or not a specified item exists within the list.
		bool contains(T* item);

		// Finds the first index at which specified item is found.
		int find(T* item);

		// Gets the list size.
		int size();

		// Adds the item into the end of the list.
		void push_back(T* item);

		// Returns the element at the specified index.
		T* at(int index);

		// Inserts the specified item at the specified index.
		void insert(T* item, int index);

		// Removes the item at the specified index.
		void removeAt(int index);

		// Removes the specified item from the list.
		void remove(T* item);

		// Creates an iterator that initially points to the first element of LinkedList.
		Iterator begin();

		// Creates an iterator that initially points to the last element of LinkedList.
		Iterator end();

		// Returns the items of this list as an array.
		T** toArray();
		
	protected:
		Node *head = nullptr, *tail = nullptr;
		int length = 0;

};

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
#endif