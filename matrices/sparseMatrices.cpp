# include <iostream>
using namespace std;

class SparseMatrixElement {
		
	public:
		SparseMatrixElement();
		SparseMatrixElement(int row, int col, int value);
		~SparseMatrixElement();

	private:
		int row;
		int col;
		int value;

	friend class SparseMatrix;
};

SparseMatrixElement :: SparseMatrixElement() {}

SparseMatrixElement :: SparseMatrixElement(int row, int col, int value) {
	this -> row = row;
	this -> col = col;
	this -> value = value;
}

SparseMatrixElement :: ~SparseMatrixElement() {
	this -> row = -1;
	this -> col = -1;
	this -> value = -1;
}

class SparseMatrix {

	enum {
		DEFAULT_CAPACITY   = 100
	};
		
	public:

		SparseMatrix();
		SparseMatrix(int rows, int cols, int numberOfNonZeroElements = DEFAULT_CAPACITY);
		~SparseMatrix();

		void print() const;

		void insert(int row, int col, int value);
		SparseMatrix add(SparseMatrix& s);
		SparseMatrix& transpose(SparseMatrix& s);
		SparseMatrix& multiply(SparseMatrix& s);

	private:

		int rows;
		int cols;
		int numberOfNonZeroElements;
		int size;
		SparseMatrixElement * data;

};

SparseMatrix :: SparseMatrix() {}
SparseMatrix :: SparseMatrix(int rows, int cols, int numberOfNonZeroElements) {
		
	this -> rows = rows;
	this -> cols = cols;
	this -> numberOfNonZeroElements = numberOfNonZeroElements;
	this -> size = 0;

	this -> data = new SparseMatrixElement[numberOfNonZeroElements];
	
	cout << "Enter the elements: ";
	int row, col, value;
	for(int i = 0; i < numberOfNonZeroElements; i++) {
		cin >> row >> col >> value;

		this -> data[i].row = row;
		this -> data[i].col = col;
		this -> data[i].value = value;
	}
	
	this -> size = numberOfNonZeroElements;
}

SparseMatrix :: ~SparseMatrix() {
	
	delete[] (this -> data);
	this -> rows = 0;
	this -> cols = 0;
	this -> numberOfNonZeroElements = 0;
	this -> size = 0;
}

void SparseMatrix :: print() const {
	
	cout << "Row\t" << "Column\t" << "Value\n";
	for(int i = 0; i < (this -> numberOfNonZeroElements); i++) {
		cout << this -> data[i].row << "\t" << this -> data[i].col << "\t" << this -> data[i].value << "\n";
	}
	cout << endl << endl;
}

void SparseMatrix :: insert(int row, int col, int value) {
		
	if(row > (this -> rows) || col > (this -> cols)) {
		cout << "Error : Not enough rows and/or columns";
		return;
	}

	this -> data[this -> size].row = row;
	this -> data[this -> size].col = col;
	this -> data[this -> size].value = value;
	++(this -> size);
}

SparseMatrix SparseMatrix :: add(SparseMatrix &s) {
	
	if((this -> rows != s.rows) || (this -> cols != s.cols)) {
		cout << "Error : Matrices have disproportionate dimensions. Cannot be added.\n\n";
		SparseMatrix null(0, 0, 0);
		return null;
	}
	
	SparseMatrix * output = new SparseMatrix(s.rows, s.cols);
	int thisPosition = 0, sPosition = 0;

	while(thisPosition < (this -> size) && sPosition < s.size) {
		
		// if row and col numbers are equal for both the matrices, we will add store in the output
		if(this -> data[thisPosition].row == s.data[sPosition].row && this -> data[thisPosition].col == s.data[thisPosition].col) {
			int addedValue = this -> data[thisPosition].value + s.data[sPosition].value;
			if(addedValue != 0) {
				output -> insert(this -> data[thisPosition].row, this -> data[thisPosition].col, this -> data[thisPosition].value + s.data[sPosition].value);
			}
//			output -> row = this -> row;
//			output -> col = this -> col;
//			output -> value = (this -> value + s.value);
			// increment the indices;
			++thisPosition;
			++sPosition;
		} else if(this -> data[thisPosition].row < s.data[sPosition].row || ((this -> data[thisPosition].row) == s.data[sPosition].row && this -> data[thisPosition].col < s.data[sPosition].col)) {
			output -> insert(this -> data[thisPosition].row, this -> data[thisPosition].col, this -> data[thisPosition].value);
//			output -> row = this -> row;
//			output -> col = this -> col;
//			output -> value = this -> value;
			++thisPosition;
		} else if(this -> data[thisPosition].row > s.data[sPosition].row || ((this -> data[thisPosition].row) == s.data[sPosition].row && this -> data[thisPosition].col > s.data[sPosition].col)) {
			output -> insert(s.data[sPosition].row, s.data[sPosition].col, s.data[sPosition].value);
//			output -> row = s.row;
//			output -> col = s.col;
//			output -> value = s.value;
			++sPosition;
		}
	}

	while(thisPosition < (this -> size)) {
		output -> insert(this -> data[thisPosition].row, this -> data[thisPosition].col, this -> data[thisPosition].value);
		++thisPosition;
	}

	while(sPosition < s.size) {
		output -> insert(s.data[sPosition].row, s.data[sPosition].col, s.data[sPosition].value);
		++sPosition;
	}

	return *output;
}

int main(void) {

	int rows, cols, numberOfNonZeroElements;
	cin >> rows >> cols >> numberOfNonZeroElements;

	SparseMatrix s(rows, cols, numberOfNonZeroElements);

	s.print();

	cin >> numberOfNonZeroElements;
	SparseMatrix s2(rows, cols, numberOfNonZeroElements);
	s2.print();

	cout << "here";

	SparseMatrix *s3 = new SparseMatrix();
	*s3 = s.add(s2);
	s3 -> print();
		
	return 0;
}
