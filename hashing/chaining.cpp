# include <iostream>
# include <cmath>
using namespace std;

const double A = 0.61803;

class HashTableNode {
		
	public:
		int data;
		HashTableNode *addressToNext;
};

int returnHashDivisionKey(int, int);
HashTableNode * insertData(HashTableNode *, int);
HashTableNode * deletion(HashTableNode *, int);
void displayHashTable(HashTableNode **, int);

int main(void) {

	unsigned short int choice;
	int sizeOfHashTable, key;
	
	// set the size of the hasTable
	sizeOfHashTable = 10;

	HashTableNode ** hashTable = new HashTableNode* [sizeOfHashTable];
	
	for(int i = 0; i < sizeOfHashTable; i++) {
		hashTable[i] = NULL;
	}

	do {
			
		cout << "\nEnter the desired option: ";
		cout << "\n1. Insert in hash table ";
		cout << "\n2. Display the hash table ";
		cout << "\n3. Delete from hash table";
		cout << "\n4. Enter 0 to exit";
		cin >> choice;

		switch(choice) {
				
			case 1:
				int data;
				cout << "\nEnter the data to insert: ";
				cin >> data;
				key = returnHashDivisionKey(data, sizeOfHashTable);
				hashTable[key] = insertData(hashTable[key], data);
				break;
				
			case 2:

				displayHashTable(hashTable, sizeOfHashTable);
				break;

			case 3:

				cout << "\nEnter the data to delete: ";
				cin >> data;

				key = returnHashDivisionKey(data, sizeOfHashTable);
				hashTable[key] = deletion(hashTable[key], data);
				break;
		}
	} while(choice != 0);

	return 0;
}

int returnHashDivisionKey(int data, int sizeOfHashTable) {
	return data % sizeOfHashTable;
}

HashTableNode * insertData(HashTableNode * PointerToChain, int data) {
	
	HashTableNode * newNode = new HashTableNode;
	HashTableNode * ptr;

	newNode -> data = data;
	newNode -> addressToNext = NULL;

	if(PointerToChain == NULL) {
		PointerToChain = newNode;
	} else {
			
		ptr = PointerToChain;
		while(ptr -> addressToNext != NULL) {
			ptr = ptr -> addressToNext;
		}

		ptr -> addressToNext = newNode;
	}
			
	return PointerToChain;
}

HashTableNode * deletion(HashTableNode * PointerToChain, int data) {
		
	if(PointerToChain == NULL) {
		cout << "\nThe data you are searching is not found.\n\n";
		return PointerToChain;
	}

	HashTableNode * toDelete = PointerToChain;

	if(PointerToChain -> data = data) {
		PointerToChain = PointerToChain -> addressToNext;

	} else {
			
		toDelete = PointerToChain -> addressToNext;
		HashTableNode * prePointer = PointerToChain;

		while(toDelete != NULL && toDelete -> data == data) {
			prePointer = toDelete;
			toDelete = toDelete -> addressToNext;
		}

		if(toDelete == NULL) {
			cout << "\nData to be deleted isn't found.\n\n";
			return PointerToChain;
		}

		prePointer -> addressToNext = toDelete -> addressToNext;
	}

	delete toDelete;
	return PointerToChain;
}

void displayHashTable(HashTableNode ** hashTable, int sizeOfHashTable) {
		
	for(int i = 0; i < sizeOfHashTable; i++) {
		
		HashTableNode * ptr = hashTable[i];
		while(ptr != NULL) {
			cout << ptr -> data << " -> ";
			ptr = ptr -> addressToNext;
		}

		cout << "\n\n";
	}
}



















