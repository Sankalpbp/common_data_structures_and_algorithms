# include <iostream>
using namespace std;

template <typename E>
class Vector {
		
	enum {
		DEFAULT_CAPACITY = 10
	};

	public:
		
		Vector(int capacity = DEFAULT_CAPACITY);
		int size() const;	// returns the current size of the vector
		bool empty() const;	// returns if the vector is empty

		void pushBack(const E& e);
		void popBack();

		~Vector();
		Vector(const Vector &v);
		Vector& operator=(const Vector &v);
		void print() const;
		const E atIndex(const int index) const;

	private:
		E* arr;
		int capacity;
		int length;	// size of the vector currently in use
};

template <typename E> Vector<E> :: Vector(int capacity)
	: arr(new E[capacity]), capacity(capacity), length(0) {}

template <typename E> int Vector<E> :: size() const {
	return length;
}

template <typename E> bool Vector<E> :: empty() const {
	return (length == 0);
}

template <typename E> Vector<E> :: ~Vector() {
		
	delete[] (this -> arr);
	length = 0;
	capacity = 0;
}

template <typename E> Vector<E> :: Vector(const Vector<E> &v) {
	
	this -> capacity = v.capacity;
	this -> length = v.length;
	this -> arr = new E[v.capacity];

	for(int i = 0; i < (v.length); i++) {
		this -> arr[i] = v.arr[i];
	}
}

template <typename E> Vector<E>& Vector<E> :: operator=(const Vector& v) {
		
	this -> capacity = v.capacity;
	this -> length = v.length;
	this -> arr = new E[capacity];

	for(int i = 0; i < (v.length); i++) {
		this -> arr[i] = v.arr[i];
	}

	return *this;
}

template <typename E> void Vector<E> :: pushBack(const E& e) {
	
	if(this -> length == capacity) {
		// that means our array is completely filled
		// we gotta create another one. 
		int * newArray = new int[2 * (this -> capacity)];

		// copy the previous array into this
		for(int i = 0; i < (this -> capacity); i++) {
			newArray[i] = this -> arr[i];
		}
		
		// now we have to delete it, and assign the newArray to our arr.

		delete[] arr;
		(this -> capacity) *= 2;
		this -> arr = newArray;
	}

	this -> arr[length] = e;
	++length;
}

template <typename E> void Vector<E> :: popBack() {
		
	if(this -> empty() == true) {
		cout << "The Vector is empty.\n\n";
		return;
	}

	--(this -> length);
}

template <typename E> const E Vector<E> :: atIndex(const int index) const {
	if(index >= length) {
		cout << "No element at " << index << "\n\n";
		return 0;
	}

	return (this -> arr[index]);
}

template <typename E> void Vector<E> :: print() const {
		
	cout << endl << endl;
	for(int i = 0; i < (this -> length); i++) {
		cout << (this -> arr[i]) << " ";
	}
	cout << endl << endl;
}

int main(void) {
		
	Vector<int> v;
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);

	v.popBack();
	v.print();

	cout << v.atIndex(0) << endl << endl;

	// its working FINE!!!
	return 0;
}



















