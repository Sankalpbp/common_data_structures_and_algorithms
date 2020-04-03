# include <iostream>
# include <climits>
# include <cmath>
using namespace std;

class queueNode {
		
	private:
		int data;
		queueNode * next;

		// both the linkedlist class and the queue class must have
		// access to the private members of this class
		// SO, THEY GOTTA BE FRIENDS, DON'T THEY?
		friend class LinkedList;
		friend class LLQueue;
};

class LinkedList {
		
	public:
		LinkedList();
		~LinkedList();

		bool empty() const;
		const int front() const;
		void addFront(const int data);
		void addEnd(const int data);
		void removeFront();
		void removeEnd();
		void print() const;

	private:
		queueNode * head;
};

LinkedList :: LinkedList()
	: head(NULL) {}

LinkedList :: ~LinkedList() {
	while(this -> empty() == false) {
		this -> removeEnd();
	}
}

bool LinkedList :: empty() const {

	if(this -> head == NULL) {
		return true;
	}
	return false;
}

const int LinkedList :: front() const {
	return (this -> head -> data);
}

void LinkedList :: addFront(const int data) {
		
	queueNode * newNode = new queueNode;
	newNode -> data = data;
	newNode -> next = this -> head;
	head = newNode;
}

void LinkedList :: addEnd(const int data) {
	
	queueNode * newNode = new queueNode;
	newNode -> data = data;
	newNode -> next = NULL;

	queueNode * ptr = this -> head;
	while(ptr -> next != NULL) {
		ptr = ptr -> next;
	}

	ptr -> next = newNode;
}

void LinkedList :: removeEnd() {
		
	if(this -> head -> next == NULL) {
		queueNode * old = this -> head;
		this -> head = NULL;
		delete old;
		return;
	}

	queueNode * old = this -> head;
	queueNode * prevOld; 

	while(old -> next != NULL) {
		prevOld = old;
		old = old -> next;
	}

	prevOld -> next = NULL;
	delete old;
}

void LinkedList :: print() const {
	queueNode * ptr = this -> head;
	
	while(ptr != NULL) {
		cout << ptr -> data << " ";
		ptr = ptr -> next;
	}
	cout << endl << endl;
}

class LLQueue {
		
	enum {
		DEFAULT_CAPACITY = 100
	};

	public:
		LLQueue();
		~LLQueue();

		int size() const;
		bool empty() const;
		const int front() const;
		void enqueue(const int data);
		void dequeue();

	private:
		LinkedList Q;
		int number;
};

LLQueue :: LLQueue()
	: Q(), number(0) {}

LLQueue :: ~LLQueue() {
	this -> number = 0;
}

int LLQueue :: size() const {
	
	return (this -> number);
}

bool LLQueue :: empty() const {
		
	if(this -> number == 0) {
		return true;
	}

	return false;
}

const int LLQueue ::front() const {
	if(this -> empty() == true) {
		cout << "Error : front of an empty queue.\n\n";
		return INT_MIN;
	}

	return Q.front();
}

void LLQueue :: enqueue(const int data) {

	++(this -> number);
	(this -> Q).addEnd(data);
}

void LLQueue :: dequeue() {

	if(this -> empty() == true) {
		cout << "Error : Dequeueing from an empty queue.\n\n";
		return;
	}

	--(this -> number);
	(this -> Q).removeEnd();
}

int main(void) {
	
	LLQueue q;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);

	cout << q.size() << endl << endl;
	cout << q.empty() << endl << endl;

	cout << q.front() << endl;
	q.dequeue();
	cout << q.front() << endl;
	q.dequeue();
	cout << q.front() << endl;
	q.dequeue();
	cout << q.front() << endl;
	q.dequeue();
	cout << q.front() << endl;
	q.dequeue();


}

























