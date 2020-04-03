# include <iostream>
using namespace std;

// the initializer list form of the constructors, nice and clean		
linkedList :: linkedList() 
	: head(NULL) {}

linkedList :: ~linkedList() {
	
	while(this -> empty() == false) {
		this -> removeEnd();
	}

//	cout << endl << endl << "linked list deleted\n";
}

bool linkedList :: empty() const {
	// "const" is used because, we don't want empty()
	// to mess with out "this" linkedList

	if(head == NULL) {
		return true;
	}

	return false;
}

const int linkedList :: front() const {
	return ((this -> head) -> data);
}

void linkedList :: addFront(const int e) {
		
	linkedListNode * newNode = new linkedListNode(e);
	newNode -> next = this -> head;
	this -> head = newNode;
}

void linkedList :: removeFront() {
		
	linkedListNode * toDelete = this -> head;
	(this -> head) = (this -> head) -> next;

	delete toDelete;
}

void linkedList :: print() const {
		
	linkedListNode * iterate = this -> head;
	while(iterate != NULL) {
		cout << iterate -> data << " ";
		iterate = iterate -> next;
	}

	cout << endl << endl;
}

void linkedList :: addEnd(const int e) {
		
	linkedListNode * newNode = new linkedListNode(e);
	newNode -> next = NULL;

	linkedListNode * temp = this -> head;
	while(temp -> next != NULL) {
		temp = temp -> next;
	}
	temp -> next = newNode;
}

void linkedList :: removeEnd() {
	
	if((this -> head) -> next == NULL) {
		removeFront();
		return;
	}

	linkedListNode * temp = this -> head;
	while(temp -> next -> next != NULL) {
		temp = temp -> next;
	}

	linkedListNode * toDelete = temp -> next;
	temp -> next = NULL;

	delete toDelete;
	return;
}

void linkedList :: addAfter(const int e, const int after) {
		
	linkedListNode * find = this -> head;

	while(find -> data != after) {
		find = find -> next;
	}

	if(find == NULL) {
		cout << after << " not found!!!\n\n";
		return;
	}

	linkedListNode * here = find -> next;
	linkedListNode * newNode = new linkedListNode(e);
	find -> next = newNode;
	newNode -> next = here;
}

void linkedList :: addBefore(const int e, const int before) {
		
	linkedListNode * find = this -> head;
	linkedListNode * beforeFind = NULL;

	while(find -> data != before) {
		beforeFind = find;
		find = find -> next;
	}

	if(find == NULL) {
		cout << before << " not found!!!\n\n";
		return;
	}

	linkedListNode * newNode = new linkedListNode(e);
	beforeFind -> next = newNode;
	newNode -> next = find;
}

const int linkedList :: size() {
		
	linkedListNode * countingNode = this -> head;
	int count = 0;
	while(countingNode != NULL) {
		count++;
		countingNode = countingNode -> next;
	}
	
	return count;
}

void linkedList :: addAtPosition(const int e, const int position) {
		
	int count = this -> size();
	if(count < position) {
		cout << "\nNot enough size!!\n\n";
	}

	linkedListNode * temp = this -> head;
	linkedListNode * newNode = new linkedListNode(e);

	int reach = position - 2;
	while(reach--) {
		temp = temp -> next;
	}

	linkedListNode * here = temp -> next;
	temp -> next = newNode;
	newNode -> next = here;
}

void linkedList :: removeAfter(const int e) {
		
	linkedListNode * temp = this -> head;

	while(temp != NULL and temp -> data != e) {
		temp = temp -> next;
	}

	// we gotta delete the element next to toDelete
	if(temp == NULL) {
		cout << e << " not found\n\n";
		return;
	}

	if(temp -> next == NULL) {
		this -> removeEnd();
		return;
	}

	if(temp -> data == e) {
		linkedListNode * toDelete = temp -> next;
		temp -> next = temp -> next -> next;
		delete toDelete;
		return;
	}
}

void linkedList :: removeFromPosition(const int position) {
		
	if(position == 1) {
		cout << "Calling removeFront()...\n";
		this -> removeFront();
		return;
	}

	if(this -> size() == position) {
		this -> removeEnd();
		return;
	}

	if(this -> size() < position) {
		cout << "Position out of the list.\n\n";	
		return;
	}

	linkedListNode * temp = this -> head;
	linkedListNode * beforeTemp = NULL;

	int count = 1;
	while(temp != NULL && count != position) {
		beforeTemp = temp;
		temp = temp -> next;
		count++;
	}
	
	linkedListNode * toDelete = beforeTemp -> next;
	beforeTemp -> next = beforeTemp -> next -> next;
	delete toDelete;
	return;
}

void linkedList :: bubbleSort() {
		
	for(int i = 0; i < (this -> size()); i++) {
		for(linkedListNode * iterator2 = this -> head; iterator2 -> next != NULL; iterator2 = iterator2 -> next) {
			if(iterator2 -> data > (iterator2 -> next -> data)) {
				swap(iterator2 -> data, iterator2 -> next -> data);
			}
		}
	}

	return;
}

void linkedList :: insertionSorted(const int e) {
		
	// we will move till the point when e is greater
	linkedListNode * temp = this -> head;
	linkedListNode * beforeTemp = NULL;

	while(temp != NULL && temp -> data < e) {
		beforeTemp = temp;
		temp = temp -> next;
	}

	linkedListNode * newNode = new linkedListNode(e);
	beforeTemp -> next = newNode;
	newNode -> next = temp;
	return;
}

