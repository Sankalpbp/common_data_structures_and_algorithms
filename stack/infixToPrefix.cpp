# include <iostream>
# include <algorithm>
# include <stack>
# include <string>
using namespace std;

int precedence(char Operator) {
		
	if(Operator == '+' || Operator == '-') {
		return 1;
	}
	
	if(Operator == '/' || Operator == '*') {
		return 2;
	}

	if(Operator == '^') {
		return 3;
	}

	return -1;
}

bool isOperand(char ch) {
		
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		return true;
	}
	return false;
}

string convertInfixToPrefix(string infixExpression) {
		
	// 1. reverse the expression
	// 2. solve for the infix to postfix
	// 3. reverse again, that's our prefix

	reverse(infixExpression.begin(), infixExpression.end());
	for(int i = 0; i < infixExpression.length(); i++) {
		if(infixExpression[i] == '(') {
			infixExpression[i] = ')';
		}
		else if(infixExpression[i] == ')') {
			infixExpression[i] = '(';
		}
	}

	stack<char> pendingOperators;
	string prefixExpression;

	for(int i = 0; i < infixExpression.length(); i++) {
		
		if(isOperand(infixExpression[i]) == true) {
			prefixExpression.push_back(infixExpression[i]);
		}

		else if(infixExpression[i] == '(') {
			pendingOperators.push(infixExpression[i]);
		}

		else if(infixExpression[i] == ')') {
			
			while(pendingOperators.empty() == false && pendingOperators.top() != '(') {
				prefixExpression.push_back(pendingOperators.top());
				pendingOperators.pop();
			}

			if(pendingOperators.top() == '(') {
				pendingOperators.pop();
			}
		}

		else {
				
			while(pendingOperators.empty() == false && precedence(pendingOperators.top()) >= precedence(infixExpression[i])) {
				prefixExpression.push_back(pendingOperators.top());
				pendingOperators.pop();
			}

			pendingOperators.push(infixExpression[i]);
		}
	}

	while(pendingOperators.empty() == false) {
		prefixExpression.push_back(pendingOperators.top());
		pendingOperators.pop();
	}

	cout << prefixExpression << endl;
	reverse(prefixExpression.begin(), prefixExpression.end());
	return prefixExpression;
}

int main(void) {
		
	string s;
	cout << "\nEnter a valid infix expression(otherwise, algorithm won't work) : ";
	cin >> s;
	
	string output = convertInfixToPrefix(s);

	if(output.empty() == false) {
		cout << output << endl << endl;
	}
	return 0;
}
