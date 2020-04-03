# include "linkedList.h"

using namespace std;

int main(void) {
		
	linkedList l;

	cout << "\nEnter the elements (Enter -1 to exit) : ";
	int value;
	cin >> value;
	while(value != -1) {
		l.addFront(value);
		cin >> value;
	}

	l.print();

	l.bubbleSort();
	l.print();

	cout << "\nENter the value to insert in the sorted linked list";
	cin >> value;
	l.insertionSorted(value);
	l.print();

	return 0;
}
