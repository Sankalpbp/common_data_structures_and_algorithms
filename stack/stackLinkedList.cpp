# include <iostream>
using namespace std;

template <typename E>
class stackNode {
		
	private:
		E data;
		stackNode<E> *next;
		friend class LinkedListStack;
};

template <typename E>
class LinkedList {
		
	public:
		LinkedList();
		~LinkedList();

		bool empty() const;
		const E front() const;
		void addFront(const E& e);
		void removeFront();

	private:
		stackNode<E> *head;
};

template <typename E>
LinkedList<E> :: LinkedList()
	: head(NULL) {}

template <typename E>
LinkedList<E> :: ~LinkedList() {
	while(this -> empty() == false) {
		this -> removeFront();
	}
}

template <typename E>
bool LinkedList<E> :: empty() const {
	return (head == NULL);
}

template <typename E>
const E LinkedList<E> :: front() const {
	return (this -> head -> data);
}

template <typename E>
void LinkedList<E> :: addFront(const E& e) {
	stackNode<E> *v = new stackNode<E>;
	v -> data = e -> data;
	v -> next = head;
	head = v;
}

template <typename E>
void LinkedList<E> :: removeFront() {
	stackNode<E> * old = head;
	head = old -> next;
	delete old;
}
	
template <typename E>
class LinkedListStack {
		
	enum {
		DEFAULT_CAPACITY = 10
	};

	public:
		
		LinkedListStack();
		int size() const;
		bool empty() const;

		const E top() const;
		void push(const E& e);
		void pop();

		~LinkedListStack();
//		LinkedListStack(LinkedListStack &s);
//		LinkedListStack& operator=(LinkedListStack &s);

	private:
		LinkedList<E> S;
		int number;
};

template <typename E> 
LinkedListStack<E> :: LinkedListStack()
	: S(), number(0) {}

template <typename E>
LinkedListStack<E> :: ~LinkedListStack() {
	number = 0;
}

template <typename E> 
int LinkedListStack<E> :: size() const {
	return number;
}

template <typename E>
bool LinkedListStack<E> :: empty() const {
	return (number == 0);
}

template <typename E>
const E LinkedListStack<E> :: top() const {
	if(this -> empty()) {
		cout << "Top of an empty stack.\n\n";
		return 0;
	}
	return S.front();
}

template <typename E>
void LinkedListStack<E> :: push(const E& e) {
	++(this -> number);
	S.addFront(e);
}

template <typename E>
void LinkedListStack<E> :: pop() {
	if(this -> empty()) {
		cout << "Popping from an empty stack.\n\n";
		return;
	}
	S.removeFront();
}

int main(void) {

	LinkedListStack<float> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	return 0;
}









