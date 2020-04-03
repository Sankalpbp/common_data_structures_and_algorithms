# include <iostream>
using namespace std;

class array {
		
	int n;
	int * arr;

	public:
		
		array(int n, bool filled = false) {
			
			this -> n = n;
			this -> arr = new int[this -> n];

			if(filled == false) {

				cout << "\nEnter the elements : ";
				for(int i = 0; i < (this -> n); i++) {
					cin >> (this -> arr[i]);
				}
			}
		}

		array(array & a) {
				
			this -> n = a.n;
			this -> arr = new int[this -> n];

			for(int i = 0; i < (this -> n); i++) {
				this -> arr[i] = a.arr[i];
			}
		}

		~array() {
				
			delete[] (this -> arr);
			this -> n = 0;
		}

		array & operator=(array & a);

		int findMax();
		array* countingSort();
		void stableSort(int exponent);
		void radixSort();
		void print();
};

void array :: print() {
		
	for(int i = 0; i < (this -> n); i++) {
		cout << this -> arr[i] << " ";
	}

	cout << endl << endl;
}

array& array :: operator=(array &a) {
		
	this -> n = a.n;
	this -> arr = new int[this -> n];

	for(int i = 0; i < (this -> n); i++) {
		this -> arr[i] = a.arr[i];
	}

	return *this;
}

int array :: findMax() {
		
	int maxx = this -> arr[0];
	for(int i = 1; i < (this -> n); i++) {
		maxx = max(arr[i], maxx);
	}

	return maxx;
}

array* array :: countingSort() {
		
	int k = this -> findMax();

	int * count = new int[k + 1];
	
	// we will count the number of elements of each type
	for(int i = 0; i < (this -> n); i++) {
		count[this -> arr[i]]++;
	}

	// lets create an output array to hold the output
	// in the end, we will copy the new output array or just return it
	array * output = new array(n, true);

	// manipulate the count array in a way, so that each symbol holds the element holds the number of 
	// elements smaller than itself in the original array, we will use this "counting" in the array

	for(int i = 1; i <= k; i++) {
		count[i] += count[i - 1];
	}

	// now, we will use the main input array and the count array to find the 
	// output array which will be sorted, will be returned or somethin'

	for(int i = 0; i < n; i++) {
		// we will find the count of the element of the array, then, will place the element at that
		// count position in the array and then, decrease the count and then, move to the next element
		output -> arr[count[this -> arr[i]] - 1] = this -> arr[i];
		count[this -> arr[i]]--;
	}

	delete[] count;
	return output;
}

void array :: stableSort(int exponent) {
	
	int * counting = new int[10];
	for(int i = 0; i < 10; i++) {
		counting[i] = 0;
	}

	array * output = new array(this -> n, true);

	for(int i = 0; i < (this -> n); i++) {
		counting[(this -> arr[i] / exponent) % 10] += 1;
	}

	for(int i = 1; i < 10; i++) {
		counting[i] += counting[i - 1];
	}

	for(int i = (this -> n) - 1; i >= 0; i--) {
		output -> arr[counting[(this -> arr[i] / exponent) % 10] - 1] = this -> arr[i];
		counting[(this -> arr[i] / exponent) % 10]--;
	}

	for(int i = 0; i < n; i++) {
		this -> arr[i] = output -> arr[i];
	}

	delete output;
	delete[] counting;
}

void array :: radixSort() {
		
	int maxx = findMax();

	for(int exponent = 1; maxx / exponent != 0; exponent *= 10) {
		stableSort(exponent);
	}
}

//void array :: bucketSort() {
		
	// bucket sort is relatively more intuitive. But it has some different applications
	// it is used to sort the numbers which are between 0 and 1, floats, of course.

	// first, we need to have some buckets
	// we will use vectors for that matter

//	vector<int> * Array = new vector<int> (10);
	// each of the 0 to 9 indices slots will hold the numbers starting from that particular index
	// example 3 will hold 0.33, 0,34, 0.36 etc.
	// while 0 will hold 0.01, 0.06, 0.09, etc.

//	for(int i = 0; i < n; i++) {
		
//	}
//}

int main(void) {
		
	int n;
	cin >> n;

	array * arr1 = new array(n);
	array arr2 = *arr1;
	array * output = arr1 -> countingSort();
	output -> print();

	delete output;
	delete arr1;

	arr2.radixSort();
	arr2.print();
	
	return 0;
}
