# include "linkedList.cpp"

class linkedListNode {
		
	private:

		int data;
		linkedListNode * next;

		linkedListNode(int data) {
			this -> data = data;
		}

		~linkedListNode() {
//			cout << endl << endl << "deleted" << endl;
		}
		// we have make linkedList class a friend so that
		// it can access the private members of the linkedListNode
		friend class linkedList;
};

class linkedList {
		
	public:
		// constructor and destructor
		linkedList();
		~linkedList();

		bool empty() const;
		// const functions are used so as not to allow the function
		// to make changes in the object which is calling it
		const int front() const;
		// we generally return a "const" when we are promising that the 
		// variable we are returning will not be modified within the function frame
		// and also that as we are returning it by value copied from the original value
		// so, the original value isn't dealt with

		// but as the built-in types like int, float are always returned by value
		// by default, so, in their context, it doesn't matter to use const
		// so the above declaration can be like 
		// int front() const;
		// but for a class X's object, it should be 
		// const X& front() const;
		// also, the returned value in this case, is not an lvalue anymore 
		// meaning, it can't be assigned to or otherwise modified.

		void addFront(const int e);
		void addEnd(const int e);
		void addAfter(const int e, const int afterThis);
		void addBefore(const int e, const int beforeThis);
		void addAtPosition(const int e, const int position);
		// this indicates that we are not gonna change 
		// the argument e that is an input, essentially
		const int size();
		void removeFront();
		void removeEnd();
		void removeAfter(const int e);
		void removeFromPosition(const int position);
		void print() const;
		void bubbleSort();
		void insertionSorted(const int e);

	private:
		linkedListNode *head;
};
