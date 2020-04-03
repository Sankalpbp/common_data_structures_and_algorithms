# include <iostream>
# include <climits>
using namespace std;

class stackNode {
		
	private:
		int data;
		stackNode *next;

	// LinkedListStack needs to access the private data
	friend class LLStack;
	friend class LinkedList;
};

class LinkedList {
		
	public:
		LinkedList();
		~LinkedList();

		bool empty() const;
		const int front() const;
		void addFront(const int data);
		void removeFront();

	private:
		stackNode *head;
};

LinkedList :: LinkedList() 
	: head(NULL) {}

LinkedList :: ~LinkedList() {
	while(this -> empty() == false) {
		this -> removeFront();
	}
};

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
	stackNode * newNode = new stackNode;
	newNode -> data = data;
	newNode -> next = this -> head;
	head = newNode;
}

void LinkedList :: removeFront() {
	stackNode * old = this -> head;
	this -> head = this -> head -> next;
	delete old;
}

class LLStack {
	
	enum {
		DEFAULT_CAPACITY = 100
	};

	public:
		
		LLStack();
		~LLStack();

		int size() const;
		bool empty() const;
		const int top() const;
		void push(const int data);
		void pop();

	private:
		LinkedList S;
		int number;
};

LLStack :: LLStack() 
	: S(), number(0) {}

int LLStack :: size() const {
	return number;
}

LLStack :: ~LLStack() {
	// by default the destructor of LinkedList will be called to destroy S
	number = 0;
}

bool LLStack :: empty() const {
	if(number == 0) {
		return true;
	}
	return false;
}

const int LLStack :: top() const {
	if(this -> empty() == true) {
		cout << "Error : top of an empty stack";	
		return INT_MIN;
	}

	return S.front();
}

void LLStack :: push(const int data) {
	++(this -> number);
	S.addFront(data);
}

void LLStack :: pop() {
	if(this -> empty() == true) {
		cout << "Error : Popping from an empty Stack.\n\n";
		return;
	}
	S.removeFront();
	--(this -> number);
}

int main(void) {
		
	LLStack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	return 0;
}
