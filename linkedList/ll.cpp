# include <iostream>
using namespace std;

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
		

		void reverse();
		void mergeSort();

	private:
		linkedListNode *head;
};

// the initializer list form of the constructors, nice and clean		
linkedList :: linkedList() 
	: head(NULL) {}

linkedList :: ~linkedList() {
	
	while(this -> empty() == false) {
		this -> removeEnd();
	}

//	cout << endl << endl << "linked list deleted\n";
}

bool linkedList :: empty() const {
	// "const" is used because, we don't want empty()
	// to mess with out "this" linkedList

	if(head == NULL) {
		return true;
	}

	return false;
}

const int linkedList :: front() const {
	return ((this -> head) -> data);
}

void linkedList :: addFront(const int e) {
		
	linkedListNode * newNode = new linkedListNode(e);
	newNode -> next = this -> head;
	this -> head = newNode;
}

void linkedList :: removeFront() {
		
	linkedListNode * toDelete = this -> head;
	(this -> head) = (this -> head) -> next;

	delete toDelete;
}

void linkedList :: print() const {
		
	linkedListNode * iterate = this -> head;
	while(iterate != NULL) {
		cout << iterate -> data << " ";
		iterate = iterate -> next;
	}

	cout << endl << endl;
}

void linkedList :: addEnd(const int e) {
		
	linkedListNode * newNode = new linkedListNode(e);
	newNode -> next = NULL;

	linkedListNode * temp = this -> head;
	while(temp -> next != NULL) {
		temp = temp -> next;
	}
	temp -> next = newNode;
}

void linkedList :: removeEnd() {
	
	if((this -> head) -> next == NULL) {
		removeFront();
		return;
	}

	linkedListNode * temp = this -> head;
	while(temp -> next -> next != NULL) {
		temp = temp -> next;
	}

	linkedListNode * toDelete = temp -> next;
	temp -> next = NULL;

	delete toDelete;
	return;
}

void linkedList :: addAfter(const int e, const int after) {
		
	linkedListNode * find = this -> head;

	while(find -> data != after) {
		find = find -> next;
	}

	if(find == NULL) {
		cout << after << " not found!!!\n\n";
		return;
	}

	linkedListNode * here = find -> next;
	linkedListNode * newNode = new linkedListNode(e);
	find -> next = newNode;
	newNode -> next = here;
}

void linkedList :: addBefore(const int e, const int before) {
		
	linkedListNode * find = this -> head;
	linkedListNode * beforeFind = NULL;

	while(find -> data != before) {
		beforeFind = find;
		find = find -> next;
	}

	if(find == NULL) {
		cout << before << " not found!!!\n\n";
		return;
	}

	linkedListNode * newNode = new linkedListNode(e);
	beforeFind -> next = newNode;
	newNode -> next = find;
}

const int linkedList :: size() {
		
	linkedListNode * countingNode = this -> head;
	int count = 0;
	while(countingNode != NULL) {
		count++;
		countingNode = countingNode -> next;
	}
	
	return count;
}

void linkedList :: addAtPosition(const int e, const int position) {
		
	int count = this -> size();
	if(count < position) {
		cout << "\nNot enough size!!\n\n";
	}

	linkedListNode * temp = this -> head;
	linkedListNode * newNode = new linkedListNode(e);

	int reach = position - 2;
	while(reach--) {
		temp = temp -> next;
	}

	linkedListNode * here = temp -> next;
	temp -> next = newNode;
	newNode -> next = here;
}

void linkedList :: removeAfter(const int e) {
		
	linkedListNode * temp = this -> head;

	while(temp != NULL and temp -> data != e) {
		temp = temp -> next;
	}

	// we gotta delete the element next to toDelete
	if(temp == NULL) {
		cout << e << " not found\n\n";
		return;
	}

	if(temp -> next == NULL) {
		this -> removeEnd();
		return;
	}

	if(temp -> data == e) {
		linkedListNode * toDelete = temp -> next;
		temp -> next = temp -> next -> next;
		delete toDelete;
		return;
	}
}

void linkedList :: removeFromPosition(const int position) {
		
	if(position == 1) {
		cout << "Calling removeFront()...\n";
		this -> removeFront();
		return;
	}

	if(this -> size() == position) {
		this -> removeEnd();
		return;
	}

	if(this -> size() < position) {
		cout << "Position out of the list.\n\n";	
		return;
	}

	linkedListNode * temp = this -> head;
	linkedListNode * beforeTemp = NULL;

	int count = 1;
	while(temp != NULL && count != position) {
		beforeTemp = temp;
		temp = temp -> next;
		count++;
	}
	
	linkedListNode * toDelete = beforeTemp -> next;
	beforeTemp -> next = beforeTemp -> next -> next;
	delete toDelete;
	return;
}

void linkedList :: bubbleSort() {
		
	for(int i = 0; i < (this -> size()); i++) {
		for(linkedListNode * iterator2 = this -> head; iterator2 -> next != NULL; iterator2 = iterator2 -> next) {
			if(iterator2 -> data > (iterator2 -> next -> data)) {
				swap(iterator2 -> data, iterator2 -> next -> data);
			}
		}
	}

	return;
}

void linkedList :: insertionSorted(const int e) {
		
	// we will move till the point when e is greater
	linkedListNode * temp = this -> head;
	linkedListNode * beforeTemp = NULL;

	while(temp != NULL && temp -> data <= e) {
		beforeTemp = temp;
		temp = temp -> next;
	}

	linkedListNode * newNode = new linkedListNode(e);
	beforeTemp -> next = newNode;
	newNode -> next = temp;
	return;
}

void linkedList :: reverse() {
	
	linkedListNode * current = this -> head;
	linkedListNode * previous = NULL;
	linkedListNode * Next;

	while(current != NULL) {
		Next = current -> next;
		current -> next = previous;
		previous = current;
		current = Next;
	}

	this -> head = previous;

}

int main(void) {
		
	linkedList l;

	cout << "\nEnter the elements (Enter -1 to exit) : ";
	int value;
	cin >> value;
	while(value != -1) {
		l.addFront(value);
		cin >> value;
	}

	l.print();

	l.bubbleSort();
	l.print();

	cout << "\nENter the value to insert in the sorted linked list";
	cin >> value;
	l.insertionSorted(value);
	l.print();

	l.reverse();
	l.print();
	return 0;
}
