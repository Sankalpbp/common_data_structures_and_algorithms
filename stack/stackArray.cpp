# include <iostream>
# include <climits>
using namespace std;

template <typename E>
class ArrayStack {
		
	// this defines the default stack capacity
	enum {
		DEFAULT_CAPACITY = 100 
	};

	public:

	// A simple note : like we call the three of those : 
	// the destructor, a copy constructor, and the assignment operator
	// the Big Three in C++
	// they are also called the housekeeping functions
		
		ArrayStack(int capacity = DEFAULT_CAPACITY);
		int size() const;	// present number of items in the stack
		bool empty() const;	// is the stack empty?
		
		// to return top, there is a possibility that the stack is empty
		// in that case, an exception is thrown.
		const E top() const;
		void push(const E& e);
		void pop();

		// house keeping functions
		~ArrayStack();
		ArrayStack(ArrayStack &s);
		ArrayStack& operator=(ArrayStack<E> &s);

	private:
		E* S;
		int capacity;
		int topOfStack;	 // index of the top of the stack at any given time
};

// constructor as an initializer list
template <typename E> ArrayStack<E> :: ArrayStack(int capacity) 
	: S(new E[capacity]), capacity(capacity), topOfStack(-1) {}

template <typename E> ArrayStack<E> :: ~ArrayStack() {
	delete[] (this -> S);
	this -> topOfStack = -1;
}

template <typename E> ArrayStack<E> :: ArrayStack(ArrayStack<E> &s) {
	this -> capacity = s.capacity;
	this -> S = new E[s.capacity];

	for(int i = 0; i < s.capacity; i++) {
		this -> S[i] = s.S[i];
	}
}

template <typename E> ArrayStack<E> & ArrayStack<E> :: operator=(ArrayStack<E> &s) {
	this -> capacity = s.capacity;
	this -> S = new E[s.capacity];

	for(int i = 0; i < s.capacity; i++) {
		this -> S[i] = s.S[i];
	}

	return *this;
}

template <typename E> int ArrayStack<E> :: size() const {
	return (topOfStack + 1);
}

template <typename E> bool ArrayStack<E> :: empty() const {
	return (topOfStack < 0);
}

template <typename E> 
const E ArrayStack<E> :: top() const {
		
	if(this -> empty() == true) {
		cout << "Top of an empty Stack.\n\n";
		return INT_MIN;
	}
	return S[topOfStack];
}

template <typename E>
void ArrayStack<E> :: push(const E& e) {
		
	if(this -> size() == capacity) {
		cout << "Allocating more space for the stack.\n\n";
		E * newMemory = new E[int(1.5 * capacity)];
		for(int i = 0; i < capacity; i++) {
			newMemory[i] = this -> S[i];
		}

		newMemory[capacity] = e;

		capacity = 2 * capacity;
		delete[] (this -> S);
		this -> S = newMemory;
	}
	// increment the top
	++topOfStack;
	S[topOfStack] = e;
}

template <typename E>
void ArrayStack<E> :: pop() {
	
	if(this -> empty() == true) {
		cout << "Popping from an empty Stack.\n\n";
		return;
	}

	--topOfStack;
}

int main(void) {
		
	ArrayStack<int> St;
	St.push(1);
	St.push(2);
	St.push(3);

	cout << St.top() << endl;
	St.pop();
	cout << St.top() << endl;
	St.pop();
	cout << St.top() << endl;
	St.pop();
	cout << St.top() << endl;

	for(int i = 0; i < 110; i++) {
		St.push(i);
	}

	while(St.empty() == false) {
		cout << St.top();
		cout << " ";
		St.pop();
	}
	return 0;
}




