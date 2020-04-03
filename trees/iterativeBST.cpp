# include <iostream>
# include <stack>
# include <queue>
using namespace std;

class BSTNode {
		
	public:
		int data;
		BSTNode * left;
		BSTNode * right;
};

BSTNode * newNode(int data) {
		
	BSTNode * node = new BSTNode;
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;

	return node;
}

BSTNode * insert(BSTNode * root, int data) {
		
	BSTNode * node = newNode(data);

	// pointer to start traversing the tree from root downwards, so as to
	// get the position where to insert the node
	BSTNode * x = root;

	// pointer to store the parent of the x as it moves
	BSTNode * y = NULL;	// the parent of root is NULL

	// our quest will finish when we hit NULL
	while(x != NULL) {
			
		// set y to x and move x to the next potential node
		y = x;

		if(data > (x -> data)) {
			x = x -> right;
		} else {
			x = x -> left;
		}
	}

	// if y came out to be NULL, that means, x was NULL in the first place
	// and y will be our new root;
	if(y == NULL) {
		y = newNode(data);
		root = y;
	} else if(data > (y -> data)) {
		y -> right = newNode(data);
	} else if(data < (y -> data)) {
		y -> left = newNode(data);
	}

	return root;
}

void inorder(BSTNode * root) {
	if(root != NULL) {
		inorder(root -> left);
		cout << root -> data << " ";
		inorder(root -> right);
	}
}

int height(BSTNode * root) {
		
	if(root == NULL) {
		return 0;
	}

	if(root -> left == NULL && root -> right == NULL) {
		return 1;
	}

	queue<BSTNode *> q;
	q.push(root);
	BSTNode * current;

	int height = 0;

	// the loop will traverse for height number of times
	while(q.empty() == false) {
			
		int size = q.size();

		// this will take out the nodes of a level and put the nodes of the next level
		// essentially cover a level, hence, can be used to know the height
		while(size--) {
				
			current = q.front();
			q.pop();

			if(current -> left != NULL) {
				q.push(current -> left);
			}

			if(current -> right != NULL) {
				q.push(current -> right);
			}
		}

		height++;
	}

	return height;
}

void levelOrderTraversal(BSTNode * root) {
		
	queue<BSTNode *> q;
	q.push(root);

	BSTNode * current;

	while(q.empty() == false) {
			
		current = q.front();
		cout << current -> data << " ";
		q.pop();

		if(current -> left != NULL) {
			q.push(current -> left);
		}
		if(current -> right != NULL) {
			q.push(current -> right);
		}
	}
	cout << endl << endl;
}

void search(BSTNode * &node, BSTNode * &parent, int key) {
		
	while(node != NULL && node -> data != key) {
		
		parent = node;

		if(key < (node -> data)) {
			node = node -> left;
		} else {
			node = node -> right;
		}
	}
}

void iterativeOneStackPostorder(BSTNode * root) {
		
	if(root == NULL) {
		return;
	}

	stack<BSTNode *> pendingNodes;
	BSTNode * current = root;

	while(pendingNodes.empty() == false || current != NULL) {
			
		// push onto the stack, until we get to the leftmost node
		if(current != NULL) {
			pendingNodes.push(current);
			current = current -> left;
			continue;
		}

		// we check that if, current has a right?
		BSTNode * previous = pendingNodes.top() -> right;
		// if it doesn't, then, we will be sure to pop the current
		// as we are going through the left and then, there is no right, so, now LEFT - RIGHT - ROOT
		if(previous == NULL) {
			previous = pendingNodes.top();
			pendingNodes.pop();
			cout << previous -> data << " ";

			// we will pop out of the stack
			// and print, if stack is not empty(of course) and ...
			// if current is the right child of the top of the stack

			// as if it is the right child of its parent, then, we are certain,
			// that both the left and right subtrees have successfully been printed
			while(pendingNodes.empty() == false && pendingNodes.top() -> right == previous) {
				previous = pendingNodes.top();
				pendingNodes.pop();
				cout << previous -> data << " ";
			}
		} else {
			current = previous;
		}
	}

	cout << endl << endl;
}
		


/*
void deleteNode(BSTNode * &root, int key) {
		
	BSTNode * parent = NULL;
	Node * current = root;

	search(current, parent, key);

	if(current == NULL) {
		cout << "Error : Entry not found.\n\n";
		return;
	}

	// NODE FOUND!!!

	// node to be deleted has no children
	if(current -> left == NULL && current -> right == NULL) {
		
		// if node to be deleted is not the root node,
		// then, set its parent's left/right child to NULL
		if(current != root) {
			
			if(parent -> left == current) {
				parent -> left = NULL;
			} else {
				parent -> right = NULL;
			}
		}

		// if node is root, that is, tree has only one node, that is, root itself
		else {
			root = NULL;
		}

		delete current;
	}

	// the node to be deleted has two children
	else if(current -> left != NULL && current -> right != NULL) {
		
		BSTNode * parent = current;
		BSTNode * successor = current -> right;

		while(successor -> left != NULL) {
			parent = successor;
			successor = successor -> left;
		}

		// copy the successor's value to the current node
		// and delete it
		current -> data = successor -> data;

		if(parent -> left == successor) {
			parent -> left = NULL;
		} else {
			parent -> right = NULL;
		}

		delete successor;
	}
}
*/

int main(void) {
		
	BSTNode * root = NULL;
	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 6);
	root = insert(root, 8);
	root = insert(root, 1);

	inorder(root);
	cout << endl << endl;
	iterativeOneStackPostorder(root);

	cout << endl << endl;
	levelOrderTraversal(root);

	cout << height(root) << endl;

	BSTNode * node = root;
	BSTNode * parent = NULL;

	search(node, parent, 6);
	if(node == NULL) {
		cout << "Key not found.\n\n";
	} else {
		cout << node -> data << " ";
		cout << parent -> data << endl;;
	}
	return 0;
}












