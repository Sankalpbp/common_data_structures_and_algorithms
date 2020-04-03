# include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

class trieNode {
		
	public:
		trieNode * children[ALPHABET_SIZE];
		bool isEndOfWord;
};

trieNode * getNode(void) {
		
	trieNode * pNode = new trieNode;
	pNode -> isEndOfWord = false;

	for(int i = 0; i < ALPHABET_SIZE; i++) {
		pNode -> children[i] = NULL;
	}

	return pNode;
}

void insert(trieNode * root, string key) {
		
	// a pointer to crawl down the trie
	trieNode * crawlingPointer = root;

	for(int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';

		if(crawlingPointer -> children[index] == NULL) {
			crawlingPointer -> children[index] = getNode();
		}

		// help the crawler to move down
		crawlingPointer = crawlingPointer -> children[index];
	}

	crawlingPointer -> isEndOfWord = true;
}

bool search(trieNode * root, string key) {
		
	trieNode * crawlingPointer = root;

	for(int i = 0; i < key.length(); i++) {
		
		int index = key[i] - 'a';
		if(crawlingPointer -> children[index] == NULL) {
			return false;
		}

		crawlingPointer = crawlingPointer -> children[index];
	}

	if(crawlingPointer != NULL && crawlingPointer -> isEndOfWord == true) {
		return true;
	}

	return false;
}

int main(void) {
		
	int n;
	cin >> n;

	string * key;
	key = new string[n];

	for(int i = 0; i < n; i++) {
		cin >> key[i];
	}

	// make the root of the trie, which would essentially be a symbol for 
	// no alphabet, and the stuff starts from its children
	trieNode * root = getNode();
	for(int i = 0; i < n; i++) {
		insert(root, key[i]);
	}

	string searchString;
	cin >> searchString;

	while(searchString.compare("no") != 0) {

		if(search(root, searchString) == true) {
			cout << "\nFound.";
		} else {
			cout << "\nNot Found.";
		}
		cin >> searchString;
	}

	return 0;
}

































