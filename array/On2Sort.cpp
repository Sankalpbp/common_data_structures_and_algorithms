# include <iostream>
using namespace std;

class array {
		
	int n;
	int * arr;

	public:
		array(int n) {
			this -> n = n;
			this -> arr = new int[n];

			cout << "\nEnter the elements : ";
			for(int i = 0; i < n; i++) {
				cin >> arr[i];
			}
		}

		array(const array & a) {
			this -> n = a.n;
			this -> arr = new int[a.n];

			for(int i = 0; i < a.n; i++) {
				this -> arr[i] = a.arr[i];
			}
		}

		array & operator= (const array & a) {
			this -> n = a.n;
			this -> arr = new int[a.n];

			for(int i = 0; i < a.n; i++) {
				this -> arr[i] = a.arr[i];
			}

			return *this;
		}

		void print();
		void insertionSort();
		void selectionSort();
		void bubbleSort();
		void efficientBubbleSort();
};

void array :: bubbleSort() {
		
	// things to know about bubble sort
	// the outer loop is here just to loop for (n - 1) number of times
	// it has no say in the algorithm itself
	// the inner loop is the logic part, which is nothing but comparing and swapping each element, which doesn't satisfy the sorting logic
	for(int j = 0; j < (this -> n) - 1; j++) {
		// we will start from the end
		for(int i = (this -> n) - 1; i >= 0; i--) {
			if(this -> arr[i] < this -> arr[i - 1]) {
				swap(this -> arr[i], this -> arr[i - 1]);
			}
		}
	}
}

void array :: efficientBubbleSort() {
		
	// the idea is to stop looping, if none of the elements during the elements gets swapped
	// as that is precisely the condition for sorted array
	int count = 0;
	for(int j = 0; j < (this -> n) - 1; j++) {
		bool swapping = false;
		count++;
		for(int i = (this -> n) - 1; i >= 0; i--) {
			if(this -> arr[i] < this -> arr[i - 1]) {
				swapping = true;
				swap(this -> arr[i], this -> arr[i - 1]);
			}
		}

		if(swapping == false) {
			cout << "We have used : " << n - 1 - count << " less loop comparisons." << endl;
			break;
		}
	}
}

void array :: selectionSort() {
		
	// we will pick an element and put it into its correct position
	// we will do this for n - 1 elements

	for(int i = 0; i < ((this -> n) - 1); i++) {
		int minimumIndex = i;

		for(int j = i + 1; j < (this -> n); j++) {
			if(this -> arr[minimumIndex] > this -> arr[j]) {
				minimumIndex = j;
			}
		}

		swap(this -> arr[minimumIndex], this -> arr[i]);
	}
}

void array :: insertionSort() {
		
	// we will find the element and put this into the sorted array
	// the trivial sorted array - single element, the first one

	for(int j = 1; j < (this -> n); j++) {
		int elementToPut = this -> arr[j];

		int i = j - 1;
		while(i >= 0 && this -> arr[i] > elementToPut) {
			this -> arr[i + 1] = this -> arr[i];
			i--;
		}
		
		this -> arr[i + 1] = elementToPut;
	}
}

void array :: print() {
		
	for(int i = 0; i < (this -> n); i++) {
		cout << this -> arr[i] << " ";
	}

	cout << endl << endl;
}

int main(void) {
		
	int n;
	cin >> n;

	array * arr = new array(n);
	array arr2 = *arr;
	array arr3 = *arr;
	array arr4 = *arr;

	arr2.insertionSort();
	arr2.print();

	arr -> selectionSort();
	arr -> print();

	arr3.bubbleSort();
	arr3.print();

	arr4.efficientBubbleSort();
	arr4.print();

	return 0;
}
