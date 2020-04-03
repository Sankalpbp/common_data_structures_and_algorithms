# include <iostream>
using namespace std;

class SparseMatrix {
		
	enum {
		DEFAULT_CAPACITY = 100
	};

	public:

		SparseMatrix(int rows, int cols);
		void insert(int row, int col, int value);
		void add(SparseMatrix s);
		SparseMatrix transpose();
		void multiply(SparseMatrix s);
		void print();

	private:

	int ** data;
	int rows, cols;

	int length;
};

// zeroth column = rowNumber
// first column = columnNumber
// second column = value
SparseMatrix :: SparseMatrix(int rows, int cols) {
		
	this -> rows = rows;
	this -> cols = cols;

	this -> length = 0;
	this -> data = new int* [DEFAULT_CAPACITY];

	for(int i = 0; i < DEFAULT_CAPACITY; i++) {
		data[i] = new int[3];
	}
}

void SparseMatrix :: insert(int row, int col, int value) {
		
	if(row > (this -> rows) || col > (this -> cols)) {
		cout << "Error : Wrong Entry.\n\n";
		return;
	}

	data[this -> length][0] = row;
	data[this -> length][1] = col;
	data[this -> length][2] = value;

	++(this -> length);
}
		
void SparseMatrix :: add(SparseMatrix s) {
		
	if(this -> rows != s.rows || this -> cols != s.cols) {
		cout << "\nError : Matrices can't be added.\n\n";
		return;
	}

	int thisPosition = 0;
	int sPosition = 0;
	SparseMatrix result(this -> rows, this -> cols);

	while(thisPosition < (this -> length) && sPosition < s.length) {
			
		if((this -> data[thisPosition][0] > s.data[sPosition][0]) ||
				(this -> data[thisPosition][0] == s.data[sPosition][0] && 
				 this -> data[thisPosition][1] > s.data[sPosition][1])) {
				
			result.insert(s.data[sPosition][0], s.data[sPosition][1], s.data[sPosition][2]);
			++sPosition;
		}

		else if((this -> data[thisPosition][0] < s.data[sPosition][0]) || 
				(this -> data[thisPosition][0] == s.data[sPosition][0] && 
				 this -> data[thisPosition][1] < s.data[sPosition][1])) {
				
			result.insert(this -> data[thisPosition][0], this -> data[thisPosition][1], this -> data[thisPosition][2]);
			++(thisPosition);
		}
		
		else {
				
			int addedValue = this -> data[thisPosition][2] + s.data[sPosition][2];
			if(addedValue != 0) {
				result.insert(this -> data[thisPosition][0], this -> data[thisPosition][1], this -> data[thisPosition][2] + s.data[thisPosition][2]);
			}

			++(thisPosition);
			++(sPosition);
		}
	}

	while(thisPosition < (this -> length)) {
		result.insert(this -> data[thisPosition][0], this -> data[thisPosition][1], this -> data[thisPosition][2]);
		++(thisPosition);
	}

	while(sPosition < (s.length)) {
		result.insert(s.data[thisPosition][0], s.data[thisPosition][1], s.data[thisPosition][2]);
		++(sPosition);
	}

	result.print();
}

void SparseMatrix :: print() {
		
	cout << "\nDimensions : " << this -> rows << "x" << this -> cols << endl;
	cout << "\nRow\tColumn\tValue\n";

	for(int i = 0; i < (this -> length); i++) {
		cout << data[i][0] << "\t" << data[i][1] << "\t" << data[i][2] << endl;
	}
}

SparseMatrix SparseMatrix :: transpose() {
		
	// invert the number of rows and columns
	SparseMatrix result(this -> cols, this -> rows);

	result.length = length;
	int t
}

int main(void) {
		
	SparseMatrix a(4, 4);
	SparseMatrix b(4, 4);

	a.insert(1, 2, 10); 
    a.insert(1, 4, 12); 
    a.insert(3, 3, 5); 
    a.insert(4, 1, 15); 
    a.insert(4, 2, 12); 
    b.insert(1, 3, 8); 
    b.insert(2, 4, 23); 
    b.insert(3, 3, 9); 
    b.insert(4, 1, 20); 
    b.insert(4, 2, 25);

	cout << "Addition: ";
    a.add(b);
    cout << "\nMultiplication: ";

	return 0;
}






























