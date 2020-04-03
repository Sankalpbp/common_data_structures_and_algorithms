# include <iostream>
using namespace std;

class Node {
		
	public:

		int data;
		Node * next;
};

Node *SortedMerge(Node *a, Node *b);
void FrontBackSplit(Node * source, Node ** frontReference, Node ** backReference);

void mergeSort(Node ** headReference) {
		
	Node * head = *headReference;
	Node * a;
	Node * b;

	// base case
	if((head == NULL) || (head -> next) == NULL) {
		return;
	}

	// split head into 'a' and 'b' sublists
	FrontBackSplit(head, &a, &b);

	// Recursively sort the sublists
	mergeSort(&a);
	mergeSort(&b);

	// merge the two sorted lists together
	*headReference = SortedMerge(a, b);
}

Node * SortedMerge(Node * a, Node * b) {
		
	Node * result = NULL;

	// base cases, if one is empty, return another one
	// as both are pointing to sorted lists
	if(a == NULL) {
		return b;
	}

	if(b == NULL) {
		return a;
	}

	// pick either a or b, and recur
	if(a -> data <= b -> data) {
		result = a;
		result -> next = SortedMerge(a -> next, b);
	} else {
		result = b;
		result -> next = SortedMerge(a, b -> next);
	}

	return result;
}

void FrontBackSplit(Node * source, Node ** frontReference, Node ** backReference) {
		
	Node * fast;
	Node * slow;
	slow = source;
	fast = source -> next;

	// same old slow and fast pointers to find the middle of the list
	while(fast != NULL) {
		fast = fast -> next;
		if(fast != NULL) {
			slow = slow -> next;
			fast = fast -> next;
		}
	}

	// 'slow' is before the midpoint in the list
	*frontReference = source;
	*backReference = slow -> next;

	slow -> next = NULL;
}

void printList(Node * head) {
		
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}

void push(Node ** headReference, int data) {
		
	Node * newNode = new Node();
	newNode -> data = data;
	newNode -> next = *headReference;
	*headReference = newNode;
}

int main(void) {
		
	Node * result = NULL;
	Node * a = NULL;
	
	int value;
	cin >> value;
	while(value != -1) {
		push(&a, value);
		cin >> value;
	}

	printList(a);
	mergeSort(&a);
	printList(a);

	return 0;
}
























