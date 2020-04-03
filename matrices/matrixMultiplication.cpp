# include <iostream>
using namespace std;

void print(int ** matrix, int rows, int cols) {
	
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
}

int ** multiplyMatrices(int ** matrix1, int rows1, int cols1, int ** matrix2, int rows2, int cols2) {
	
	if(cols1 != rows2) {
		cout << "Error : Matrices incompatible for multiplication.\n\n";
		return NULL;
	}
	// for each position in the first matrix

	int ** output = new int* [rows1];
	for(int i = 0; i < rows1; i++) {
		output[i] = new int[cols2];
	}

	for(int i = 0; i < rows1; i++) {
		for(int j = 0; j < cols2; j++) {
			
			int sum = 0;
			for(int k = 0; k < cols1; k++) {
				sum += (matrix1[i][k] * matrix2[k][j]);
			}
			output[i][j] = sum;
		}
	}

	return output;
}

int main(void) {
		
	int n;
	cin >> n;

	int m;
	cin >> m;

	int ** matrix1 = new int * [n];
	for(int i = 0; i < n; i++) {
		matrix1[i] = new int[m];
		for(int j = 0; j < m; j++) {
			cin >> matrix1[i][j];
		}
	}

	int k, l;
	cin >> k >> l;
	int ** 	matrix2 = new int * [k];
	for(int i = 0; i < k; i++) {
		matrix2[i] = new int[l];
		for(int j = 0; j < l; j++) {
			cin >> matrix2[i][j];
		}
	}

	int ** output =	multiplyMatrices(matrix1, n, m, matrix2, k, l);
	if(output != NULL) {
		print(output, n, l);
	}

	return 0;
}
