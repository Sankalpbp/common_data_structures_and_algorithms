# include <iostream>
using namespace std;

class Heap {
		
	int n;
	int *arr;

	public:
		Heap(int n) {
			
			this -> n = n;
			this -> arr = new int[n];
			for(int i = 0; i < n; i++) {
				cin >> this -> arr[i];
			}

			this -> buildHeap();
		}

		Heap(const Heap & h) {
			this -> n = h.n;
			this -> arr = new int[h.n];

			for(int i = 0; i < h.n; i++) {
				this -> arr[i] = h.arr[i];
			}
		}

		Heap& operator=(const Heap & h) {
			this -> n = h.n;
			this -> arr = new int[h.n];

			for(int i = 0; i < h.n; i++) {
				this -> arr[i] = h.arr[i];
			}

			buildHeap();
		}

		~Heap() {
				
			delete[] (this -> arr);
			n = 0;
		}

		void print();
		void heapify(int index);
		void heapify(int index, int heapSize);
		void buildHeap();
		void heapsort();
};

void Heap :: heapify(int index) {
		
	int leftChildIndex = 2 * index + 1;
	int rightChildIndex = 2 * index + 2;
	int greatest = index;

	if(leftChildIndex < (this -> n) && (this -> arr[leftChildIndex]) > (this -> arr[greatest])) {
		greatest = leftChildIndex;
	}

	if(rightChildIndex < (this -> n) && (this -> arr[rightChildIndex]) > (this -> arr[greatest])) {
		greatest = rightChildIndex;
	}

	if(greatest != index) {
		swap(this -> arr[greatest], this -> arr[index]);
		heapify(greatest);
	}
}

void Heap :: heapify(int index, int heapSize) {
		
	int leftChildIndex = 2 * index + 1;
	int rightChildIndex = 2 * index + 2;
	int greatest = index;

	if(leftChildIndex < (heapSize) && (this -> arr[leftChildIndex]) > (this -> arr[greatest])) {
		greatest = leftChildIndex;
	}

	if(rightChildIndex < (heapSize) && (this -> arr[rightChildIndex]) > (this -> arr[greatest])) {
		greatest = rightChildIndex;
	}

	if(greatest != index) {
		swap(this -> arr[greatest], this -> arr[index]);
		heapify(greatest, heapSize);
	}
}

void Heap :: buildHeap() {
		
	for(int i = (this -> n) / 2; i >= 0; i--) {
		heapify(i);
	}
}

void Heap :: print() {
		
	for(int i = 0; i < (this -> n); i++) {
		cout << (this -> arr[i]) << " ";
	}
	cout << endl << endl;
}

void Heap :: heapsort() {
		
	for(int i = (this -> n) - 1; i > 0; i--) {
		swap(this -> arr[0], this -> arr[i]);
		heapify(0, i);
	}
}

int main(void) {

	int n;
	cin >> n;

	Heap *h = new Heap(n);
	Heap h2 = *h;

	h -> print();
	h2.print();

	h -> heapsort();
	h -> print();
	h2.heapsort();
	h2.print();
	
	return 0;
}
