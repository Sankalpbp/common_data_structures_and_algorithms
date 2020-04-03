# include <iostream>
# include <stack>
using namespace std;

bool isBalanced(string expression) {
		
	stack<char> pendingCharacters;
	for(int i = 0; i < expression.size(); i++) {
		
		// if any other character other than delimiters
		if((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] >= 'Z') || (expression[i] >= '0' && expression[i] <= '9')) {
			continue;
		}

		if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
			// push the stuff onto the stack
			pendingCharacters.push(expression[i]);
			continue;
		}

		/*
		   this would be checked in two scenarios : 
		   1. i = 0, that is for the first character, that means
		   	  there has been nothing in the stack, that is not possible.
		   2. i is something else, if the ith is not an opening character, it has to be closing, and if it is closing, 
		   		then, there essentially hasn't been an opening counterpart for it, which is a problem.
		 */
		if(pendingCharacters.empty() == true) {
			return false;
		}

		char x;
		// if the character is matching with last pushed, then, its okay, otherwise, problem
		switch(expression[i]) {
			
			case ')':
				x = pendingCharacters.top();
				pendingCharacters.pop();
				if(x == '{' || x == '[') {
					return false;
				}

				break;

			case '}':
				x = pendingCharacters.top();
				pendingCharacters.pop();
				if(x == '(' || x == '[') {
					return false;
				}

				break;

			case ']':
				x = pendingCharacters.top();
				pendingCharacters.pop();
				if(x == '(' || x == '{') {
					return false;
				}

				break;
		}
	}

	// if stack is not empty till the end, there has been some problem
	return (pendingCharacters.empty() == true);
}

int main(void) {
		
	string s;
	cin >> s;

	if(isBalanced(s)) {
		cout << "\nBalanced.\n\n";
	} else {
		cout << "\nNon - Balanced.\n\n";
	}

	return 0;
}
