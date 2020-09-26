template <class T> class LinkedList
{
	class Node
	{
		friend class LinkedList;

		// Create a new instance of Node using data, last node, and next node, specify nullptr if none.
		Node(T* data, Node* last, Node* next);

		// Destructs Node and attaches nodes around it to keep the chain intact.
		~Node();

		T* data = nullptr;
		Node *next = nullptr, *last = nullptr;
	};

	public:
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
	
	protected:
		Node *head = nullptr, *tail = nullptr;
		int length = 0;

};