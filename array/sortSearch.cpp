# include <iostream>
# include <climits>
# include <cmath>
using namespace std;

// QUICK SORT
// MERGE SORT
// BINARY SEARCH

class array {
		
		int * arr;
		int n;

	public:
		void print();

		array(int n) {
			this -> n = n;
			arr = new int[n];
			cout << "\nEnter the elements : ";
			for(int i = 0; i < n; i++) {
				cin >> arr[i];
			}
		}

		array(int n, bool dontFill) {
			this -> n = n;
			arr = new int[n];
		}

		array(const array & array1) {
			this -> n = array1.n;
			this -> arr = new int[array1.n];

			for(int i = 0; i < array1.n; i++) {
				this -> arr[i] = array1.arr[i];
			}
		}

		array& operator= (const array& a) {
			
			this -> n = a.n;
			this -> arr = new int[a.n];

			for(int i = 0; i < a.n; i++) {
				this -> arr[i] = a.arr[i];
			}

			return *this;
		}

		~array() {
			delete[] (this -> arr);
			n = 0;
		}

		void merge(int left, int middle, int right);
		void mergeSort(int left, int right);
		void mergeSort();

		int partition(int left, int right);
		void quickSort(int left, int right);
		void quickSort();

		int binarySearch(int left, int right, int element);
		int binarySearch(int element);
		int binarySearchIterative(int element);
		int binarySearchIterative(int left, int right, int element);
};

int array :: binarySearch(int left, int right, int element) {
		
	if(left <= right) {
		int mid = (left + right) / 2;
		if(this -> arr[mid] == element) {
			return mid;
		} else if(this -> arr[mid] > element) {
			return binarySearch(left, mid - 1, element);
		} else {
			return binarySearch(mid + 1, right, element);
		}
	}

	return -1;
}

int array :: binarySearchIterative(int left, int right, int element) {
		
	int mid = (left + right) / 2;

	while(left <= right) {

		mid = (left + right) / 2;
		if(this -> arr[mid] == element) {
			return mid;
		} else if(this -> arr[mid] > element) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return -1;	
}

int array :: binarySearchIterative(int element) {
	return binarySearchIterative(0, n - 1, element);
}

int array :: binarySearch(int element) {
	return binarySearch(0, n - 1, element);
}

void array :: print() {
		
	for(int i = 0; i < this -> n; i++) {
		cout << this -> arr[i] << " ";
	}
	cout << endl << endl;
}

void array :: merge(int left, int middle, int right) {
		
	int leftArrSize = (middle - left + 1);
	int rightArrSize = (right - middle);

	array * leftArr = new array(leftArrSize + 1, false);
	array * rightArr = new array(rightArrSize + 1, false);

	for(int i = 0; i < leftArrSize; i++) {
		leftArr -> arr[i] = this -> arr[left + i];
	}

	for(int j = 0; j < rightArrSize; j++) {
		rightArr -> arr[j] = this -> arr[middle + 1 + j];
	}

	leftArr -> arr[leftArrSize] = INT_MAX;
	rightArr -> arr[rightArrSize] = INT_MAX;

	int i = 0; 
	int j = 0;

	for(int k = left; k <= right; k++) {
		if(leftArr -> arr[i] > rightArr -> arr[j]) {
			this -> arr[k] = rightArr -> arr[j];
			j++;
		} else {
			this -> arr[k] = leftArr -> arr[i];
			i++;
		}
	}

	delete leftArr;
	delete rightArr;
}

void array :: mergeSort(int left, int right) {
		
	if(left < right) {
		int middle = (left + right) / 2;
		mergeSort(left, middle);
		mergeSort(middle + 1, right);
		merge(left, middle, right);
	}
}

void array :: mergeSort() {
	mergeSort(0, this -> n - 1);	
}

int array :: partition(int first, int last) {
		
	// find the pivot
	int pivot = this -> arr[last];
	int i = first - 1;

	for(int j = first; j < last; j++) {
		if(pivot >= this -> arr[j]) {
			i++;
			swap(this -> arr[i], this -> arr[j]);
		}
	}

	swap(this -> arr[i + 1], this -> arr[last]);
	return i + 1;
}

void array :: quickSort(int left, int right) {
		
	if(left < right) {
		int partitioningIndex = partition(left, right);
		quickSort(left, partitioningIndex - 1);
		quickSort(partitioningIndex + 1, right);
	}
}

void array :: quickSort() {
	quickSort(0, this -> n - 1);
}

int main(void) {
		
	int n;
	cout << "\nEnter the number of elements : ";
	cin >> n;

	array arr1(n);
	array arr2 = arr1;

	arr1.mergeSort();
	arr1.print();

	int element;
	cout << "\nEnter the element to find: ";
	cin >> element;
	cout << arr1.binarySearchIterative(element) << endl << endl;

//	array * arr1 = new array(n);
//	array * arr2 = new array(arr1);
	arr2.quickSort();
	arr2.print();

	return 0;
}
