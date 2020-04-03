# include <iostream>
# include <climits>
# include <vector>
# include <algorithm>
using namespace std;

class array {
		
	int * arr;
	int n;

	public:
		void print() const;

		array(int n, bool dontFill = false);
		~array();

		int selectionUsingSort();
		int selectionUsingSort(int k);
		int selectionUsingQuickSelect();
		int selectionUsingQuickSelect(int left, int right, int k);
		int partition(int left, int right);
		int selectionUsingBubble(int k);
		int selectionUsingBubble();
};

void array :: print() const {
		
	for(int i = 0; i < (this -> n); i++) {
		cout << this -> arr[i] << " ";
	}

	cout << endl << endl;
}

array :: array(int n, bool dontFill) {
	this -> n = n;
	this -> arr = new int[n];

	if(dontFill == false) {
		cout << "\nEnter the elements: ";
		for(int i = 0; i < (this -> n); i++) {
			cin >> this -> arr[i];
		}
	}
}

array :: ~array() {
	delete[] (this -> arr);
	this -> n = 0;
}

int array :: selectionUsingSort(int k) { sort(this -> arr, (this -> arr) + (this -> n), greater<int>());

	return this -> arr[k - 1];
}

int array :: selectionUsingSort() {

	int k;
	cin >> k;
	return this -> selectionUsingSort(k);
}

int array :: selectionUsingBubble(int k) {
	// if we want kth largest, we need to sort in descending order
	// otherwise, we need to sort in the ascending order
	// here, I am going for the kth largest

	// essentially, we are sorting in a way to sort only the first k element
	for(int i = 0; i < k; i++) {
		for(int j = n - 1; j > i; j--) {
			if((this -> arr[j]) > (this -> arr[j - 1])) {
				swap(this -> arr[j], this -> arr[j - 1]);
			}
		}
	}

	return arr[k - 1];
}

int array :: selectionUsingBubble() {
	int k;
	cout << "Enter the position of the number in the sorted array : ";
	cin >> k;

	return this -> selectionUsingBubble(k);
}

int array :: partition(int left, int right) {
	int pivot = this -> arr[right];
	int i = left - 1;

	for(int j = left; j < right; j++) {
		// if the pivot is greater, move to the next element
		if(pivot >= (this -> arr[j])) {
			i++;
			swap(this -> arr[i], this -> arr[j]);
		}
	}

	swap(this -> arr[i + 1], this -> arr[right]);

	return i + 1;
}

int array :: selectionUsingQuickSelect(int left, int right, int k) {

	// we are not sorting or something, so, there won't be a case where the left == right would be true, and if it is, we will return the array element
	// this is implemented such that it will give a kth smallest element
	int partitioningIndex = partition(left, right);

	if(partitioningIndex == (k - 1)) {
		return (this -> arr[partitioningIndex]);
	} else if(partitioningIndex > (k - 1)) {
		return (this -> selectionUsingQuickSelect(left, partitioningIndex - 1, k));
	} else if(partitioningIndex < (k - 1)) {
		return (this -> selectionUsingQuickSelect(partitioningIndex + 1, right, k));
	}

	return INT_MIN;
}

int array :: selectionUsingQuickSelect() {
	int k;
	cin >> k;

	return (this -> selectionUsingQuickSelect(0, n - 1, k));
}

int main(void) {
		
	int n;
	cin >> n;
	array a(n);
	cout << a.selectionUsingBubble() << endl << endl;
//	cout << a.selectionUsingSort() << endl << endl;
//	cout << a.selectionUsingQuickSelect() << endl << endl;
	return 0;
}
