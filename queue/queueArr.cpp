# include <iostream>
# include <climits>
using namespace std;

class QueueArr {
		
	enum {
		DEFAULT_CAPACITY = 100
	};
		
	public:
		QueueArr(int capacity = DEFAULT_CAPACITY);
		QueueArr(QueueArr &q);
		~QueueArr();
		QueueArr& operator=(QueueArr &q);

		int size() const;
		bool empty() const;
		int front() const;
		void enqueue(const int data);
		void dequeue();

	private:
		
		int * Q;
		int frontOfQueue;
		int endOfQueue;
		int capacity;
};

QueueArr :: QueueArr(int capacity)
	: Q(new int[capacity]), frontOfQueue(-1), endOfQueue(0), capacity(capacity) {}

QueueArr :: QueueArr(QueueArr &q) {
	
	this -> Q = new int[q.capacity];
	this -> frontOfQueue = q.frontOfQueue;
	this -> endOfQueue = q.endOfQueue;
	this -> capacity = q.capacity;

	for(int i = 0; i < endOfQueue; i++) {
		this -> Q[i] = q.Q[i];
	}
}

QueueArr& QueueArr :: operator=(QueueArr &q) {
	
	this -> Q = new int[q.capacity];
	this -> frontOfQueue = q.frontOfQueue;
	this -> endOfQueue = q.endOfQueue;
	this -> capacity = q.capacity;

	for(int i = 0; i < endOfQueue; i++) {
		this -> Q[i] = q.Q[i];
	}

	return *this;
}

QueueArr :: ~QueueArr() {
	delete[] (this -> Q);
	this -> frontOfQueue = -1;
	this -> endOfQueue = 0;
	this -> capacity = 0;
}

int QueueArr :: size() const {
	
	if(this -> frontOfQueue == -1) {
		return 0;
	}

	return (this -> endOfQueue) - (this -> frontOfQueue);
}

bool QueueArr :: empty() const {

	if(this -> size() == 0) {
		return true;
	}

	return false;
}

void QueueArr :: enqueue(const int data) {
	
	if(this -> frontOfQueue == -1) {
		this -> frontOfQueue = 0;
	}

	if(this -> endOfQueue == this -> capacity) {
		cout << "Error : Can't Enuqueue in a full queue.\n\n";
		return;
	}

	this -> Q[this -> endOfQueue] = data;
	++(this -> endOfQueue);
}

void QueueArr :: dequeue() {
	
	if(this -> endOfQueue == 0) {
		cout << "Error : Dequeue from an empty queue.\n\n";
		return;
	}

	if(this -> endOfQueue == this -> frontOfQueue) {
		cout << "Error : Dequeue from an empty queue.\n\n";
		return;
	}

	++(this -> frontOfQueue);
}

int QueueArr :: front() const {
	if(this -> endOfQueue == 0) {
		cout << "Error : Front of an empty queue.\n\n";
		return INT_MIN;
	}
	
	if(this -> endOfQueue == this -> frontOfQueue) {
		cout << "Error : Front of an empty queue.\n\n";
		return INT_MIN;
	}

	return this -> Q[frontOfQueue];
}

int main(void) {
	
	QueueArr q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);

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

	return 0;
}









