# include <iostream>
# include <stack>
# include <climits>
using namespace std;

struct BinarySearchTreeNode {
		
	int data;
	BinarySearchTreeNode * leftChild;
	BinarySearchTreeNode * rightChild;
};

BinarySearchTreeNode * createNode(int data) {
		
	BinarySearchTreeNode * newNode = new BinarySearchTreeNode;
	newNode -> data = data;
	newNode -> leftChild = NULL;
	newNode -> rightChild = NULL;

	return newNode;
}

bool search(BinarySearchTreeNode * root, int data) {
		
	// empty tree
	if(root == NULL) {
		return false;
	}

	if(root -> data == data) {
		return true;
	}

	if(root -> data > data) {
		return search(root -> leftChild, data);
	}

	if(root -> data < data) {
		return search(root -> rightChild, data);
	}

	return false;
}

BinarySearchTreeNode * insertNode(BinarySearchTreeNode * root, int data) {
		
	if(root == NULL) {
		root = createNode(data);
	}

	else if(root -> data == data) {
		cout << "Error : Can't allow duplicacy in Binary Search Tree.\n\n";
	}

	else if(root -> data > data) {
		root -> leftChild = insertNode(root -> leftChild, data);
	}

	else if(root -> data < data) {
		root -> rightChild = insertNode(root -> rightChild, data);
	}

	return root;
}

// minimum Value Node in the tree
BinarySearchTreeNode * recursiveMinValueNode(BinarySearchTreeNode * root) {
		
	if(root == NULL || root -> leftChild == NULL) {
		return root;
	}

	return recursiveMinValueNode(root -> leftChild);
}

// maximum value node in the tree
BinarySearchTreeNode * recursiveMaxValueNode(BinarySearchTreeNode * root) {
		
	if(root == NULL || root -> rightChild == NULL) {
		return root;
	}

	return recursiveMaxValueNode(root -> rightChild);
}

// the one that will succeed me(come after me) in the inorder walk
// that will be the minimum Value node of my rightChild
BinarySearchTreeNode * inorderSuccessor(BinarySearchTreeNode * root) {
		
	if(root == NULL) {
		return root;
	}

	if(root -> rightChild == NULL) {
		cout << "Successor doesn't exist.\n\n";	
		return NULL;
	}

	return recursiveMinValueNode(root -> rightChild);
}

// the one that will preceed me(come before me) in the inorderWalk
// that will be the maximum value node of my leftChild
BinarySearchTreeNode * inorderPredecessor(BinarySearchTreeNode * root) {
		
	if(root == NULL) {
		return root;
	}

	if(root -> leftChild == NULL) {
		cout << "Predecessor doesn't exist.\n\n";
		return NULL;
	}

	return recursiveMaxValueNode(root -> leftChild);
}

void inorderWalk(BinarySearchTreeNode * root) {
		
	if(root != NULL) {
		inorderWalk(root -> leftChild);
		cout << root -> data << " ";
		inorderWalk(root -> rightChild);
	}
}

BinarySearchTreeNode * deleteNode(BinarySearchTreeNode * root, int data) {
		
	if(root == NULL) {
		cout << "\nThe data to be deleted couldn't be found.\n\n";
		return NULL;
	}

	else if(data > (root -> data)) {
		root -> rightChild = deleteNode(root -> rightChild, data);
	}
	
	else if(data < (root -> data)) {
		root -> leftChild = deleteNode(root -> leftChild, data);
	}

	else {
			
		BinarySearchTreeNode * temp = NULL;

		// if both of its children are NULL
		if(root -> leftChild == NULL && root -> rightChild == NULL) {
			delete root;
			return NULL;
		}

		// left Child is null
		else if(root -> leftChild == NULL) {
			temp = root -> rightChild;
			delete root;
			return temp;
		}

		// right child is null
		else if(root -> rightChild == NULL) {
			temp = root -> leftChild;
			delete root;
			return temp;
		}

		// both the children aren't null, we will : 
		// copy the data of the InorderSuccessor of root on the root, that essentially "deletes" the root.
		// but now, that InorderSuccessor is duplicated in the tree, we will delete it from the right subtree(InorderSuccessor is leftmost in right subtree)

		temp = inorderSuccessor(root);
		root -> data = temp -> data;

		root -> rightChild = deleteNode(root -> rightChild, temp -> data);
	}

	return root;
}

void preorderWalk(BinarySearchTreeNode * root) {
		
	if(root != NULL) {
		cout << root -> data << " ";
		preorderWalk(root -> leftChild);
		preorderWalk(root -> rightChild);
	}
}

void postorderWalk(BinarySearchTreeNode * root) {
	if(root != NULL) {
		postorderWalk(root -> leftChild);
		postorderWalk(root -> rightChild);
		cout << root -> data << " ";
	}
}
	
void iterativeInorderWalk(BinarySearchTreeNode * root) {
	
	BinarySearchTreeNode * current = root;
	stack<BinarySearchTreeNode *> pendingNodes;

	while(pendingNodes.empty() == false || current != NULL) {
		
		// fill all the nodes till the leftmost
		while(current != NULL) {
			pendingNodes.push(current);
			current = current -> leftChild;
		}

		// pop a node and print it
		current = pendingNodes.top();
		pendingNodes.pop();
		cout << current -> data << " ";

		// check the rightSubtree of the popped node
		// and play the same game again for its rightSubtree
		current = current -> rightChild;
	}

	cout << endl << endl;
}
		
void iterativePreorderWalk(BinarySearchTreeNode * root) {
		
	stack<BinarySearchTreeNode *> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.empty() == false) {
			
		BinarySearchTreeNode * current = pendingNodes.top();
		pendingNodes.pop();

		cout << current -> data << " ";

		if(current -> rightChild != NULL) {
			pendingNodes.push(current -> rightChild);
		}

		if(current -> leftChild != NULL) {
			pendingNodes.push(current -> leftChild);
		}
	}
	cout << endl << endl;
}

void iterativePostorderWalk(BinarySearchTreeNode * root) {
	
	stack<BinarySearchTreeNode *> pendingNodes;
	stack<BinarySearchTreeNode *> finalPostorder;

	pendingNodes.push(root);
	BinarySearchTreeNode * current = NULL;

	while(pendingNodes.empty() == false) {
			
		current = pendingNodes.top();
		pendingNodes.pop();
		finalPostorder.push(current);

		if(current -> leftChild != NULL) {
			pendingNodes.push(current -> leftChild);
		}

		if(current -> rightChild != NULL) {
			pendingNodes.push(current -> rightChild);
		}
	}

	while(finalPostorder.empty() == false) {
		current = finalPostorder.top();
		finalPostorder.pop();
		cout << current -> data << " ";
	}

	cout << endl << endl;
}

int heightOfTree(BinarySearchTreeNode * root) {
		
	if(root == NULL) {
		return 0;
	}

	int leftHeight = heightOfTree(root -> leftChild);
	int rightHeight = heightOfTree(root -> rightChild);

	return (1 + max(leftHeight, rightHeight));
}
		

int main(void) {
		
	BinarySearchTreeNode * root = NULL;
	
	int value;
	cin >> value;

	while(value != -1) {
		root = insertNode(root, value);
		iterativePostorderWalk(root);
		cout << "\nHeight : " << heightOfTree(root) << endl;
		cin >> value;
	}
//	iterativeInorderWalk(root);
	iterativePostorderWalk(root);
	
	cin >> value;
	while(value != -20 && root != NULL) {
		root = deleteNode(root, value);
		iterativePostorderWalk(root);
//		iterativeInorderWalk(root);
		cin >> value;
	}

	iterativePostorderWalk(root);
	return 0;
}
