# include <iostream>
using namespace std;

class BinaryTreeNode {
		
	public:
		int data;
		BinaryTreeNode * leftChild;
		BinaryTreeNode * rightChild;
};

BinaryTreeNode * createBinaryTree() {
		
	BinaryTreeNode * root = NULL;

	int data;
	cout << "\nEnter the data(Enter -1 to exit) : ";
	cin >> data;

	if(data == -1) {
		return root;	// return NULL;
	}

	// otherwise, we gotta create a node and possibly its subtrees
	root = new BinaryTreeNode;
	root -> data = data;

	cout << "\nCreating the left subtree of " << data << ": ";
	root -> leftChild = createBinaryTree();
	cout << "\nCreation of left subtree of " << data << " finished.";
	
	cout << "\nCreating the right subtree of " << data << ": ";
	root -> rightChild = createBinaryTree();
	cout << "\nCreation of right subtree of " << data << " finished.";

	return root;
}

void inorderWalk(BinaryTreeNode * root) {
		
	if(root != NULL) {
			
		inorderWalk(root -> leftChild);
		cout << root -> data << " ";
		inorderWalk(root -> rightChild);
	}
}

int main(void) {
		
	BinaryTreeNode * root = NULL;
	root = createBinaryTree();

	inorderWalk(root);
	cout << endl << endl;

	return 0;
}
