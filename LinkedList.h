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
#endif