# include <iostream>
# include <stack>

using namespace std;

bool isOperator(char ch) {
		
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
		return true;
	}

	return false;
}

bool isOperand(char ch) {
	
	if((ch >= 'a' && ch <= 'z') || ch >= 'A' && ch <= 'Z') {
		return true;
	}
	return false;
}

int precedence(char Operator) {
		
	if(Operator == '^') {
		return 3;
	}
	if(Operator == '+' || Operator == '-') {
		return 1;
	}
	if(Operator == '*' || Operator == '/') {
		return 2;
	}

	return 0;
}

bool greaterPrecedenceThanIth(char operator1, char operator2) {
	
	if(precedence(operator1) >= precedence(operator2)) {
		return true;
	}

	return false;
}


string convertInfixToPostfix(string infixExpression) {
		
	string postfixExpression;
	stack<char> pendingOperators;

	for(int i = 0; i < infixExpression.size(); i++) {
		
		if(isOperand(infixExpression[i]) == true) {
			postfixExpression.push_back(infixExpression[i]);
		} else if(isOperator(infixExpression[i]) == true) {
			
			// pop out of the stack and append to the postix until the precedence of ith is smaller
			while(pendingOperators.empty() == false && greaterPrecedenceThanIth(pendingOperators.top(), infixExpression[i]) == true) {
				postfixExpression.push_back(pendingOperators.top());
				pendingOperators.pop();
			}
			pendingOperators.push(infixExpression[i]);

		} else {
			cout << "\nError : Encountered some silly, not recognizable character.\n\n";
			return 0;
		}
	}

	while(pendingOperators.empty() == false) {
		postfixExpression.push_back(pendingOperators.top());
		pendingOperators.pop();
	}

	return postfixExpression;
}

/*
string convertInfixToPostfixWithParentheses(string infixExpression) {
		
	string postfixExpression;
	stack<char> pendingOperators;

	for(int i = 0; i < infixExpression.size(); i++) {
		
		// if operand, add to the output string
		if(isOperand(infixExpression[i]) == true) {
			postfixExpression.push_back(infixExpression[i]);
		} else if(infixExpression[i] == '(') {
			pendingOperators.push(infixExpression[i]);
		} else if(infixExpression[i] == ')') {
			
			// now, pop out of the stack and add to the output until a '(' is encountered, 
			// that is, add whatever is inside the parentheses
			while(pendingOperators.empty() == false && pendingOperators.top() == '(') {
				postfixExpression.push_back(pendingOperators.top());
				pendingOperators.pop();
			}

			if(pendingOperators.top() == '(') {
				pendingOperators.pop();
			}
		} else if(isOperator(infixExpression[i]) == true) {
				
			// if its an operand
			while(pendingOperators.empty() == false && greaterPrecedenceThanIth(pendingOperators.top(), infixExpression[i]) == true) {
				postfixExpression.push_back(pendingOperators.top());
				pendingOperators.pop();
			}

			// pop out the '(', if it's there
			if(pendingOperators.top() == '(') {
				pendingOperators.pop();
			}
			// push the operator
			pendingOperators.push(infixExpression[i]);
		}
		cout << postfixExpression << endl;
	}

	while(pendingOperators.empty() == false) {
		postfixExpression.push_back(pendingOperators.top());
		pendingOperators.pop();
	}

	cout << postfixExpression << endl;
	return postfixExpression;
}
*/

string convertInfixToPostfixWithParentheses(string infixExpression) {
		
	stack<char> pendingOperators;
	string postfixExpression;

	for(int i = 0; i < infixExpression.length(); i++) {

		// operand
		if(isOperand(infixExpression[i]) == true) {
//			postfixExpression += infixExpression[i];
			postfixExpression.push_back(infixExpression[i]);
		}

		else if(infixExpression[i] == '(') {
			pendingOperators.push(infixExpression[i]);
		}

		else if(infixExpression[i] == ')') {
			
			while(pendingOperators.empty() == false && pendingOperators.top() != '(') {
				postfixExpression.push_back(pendingOperators.top());
//				postfixExpression += pendingOperators.top();
				pendingOperators.pop();
			}

			if(pendingOperators.top() == '(') {
				pendingOperators.pop();
			}
		}

		else {
			/*
				precedence(infixExpression[i]) <= precedence(pendingOperators.top())
			*/
			while(pendingOperators.empty() == false && greaterPrecedenceThanIth(pendingOperators.top(), infixExpression[i]) == true) {
				postfixExpression.push_back(pendingOperators.top());
				pendingOperators.pop();
			}

			pendingOperators.push(infixExpression[i]);
		}
	}

	while(pendingOperators.empty() == false) {
		postfixExpression.push_back(pendingOperators.top());
		pendingOperators.pop();
	}

	cout << endl << postfixExpression << endl;
	return postfixExpression;
}

int main(void) {
		
	string s;
	cin >> s;

	// program won't provide the result for expressions with parentheses, as in general, postfix don't give much shit about them
//	string output;
//	output = convertInfixToPostfix(s);
//	if(output.empty() == false) {
//		cout << "\nPostfix for corresponding expression is : " << output << endl << endl;
//	}

	string output2 = convertInfixToPostfixWithParentheses(s);
	if(output2.empty() == false) {
		cout << "\nPostfix for corresponding expression is : " << output2 << endl << endl;
	}

	return 0;
}
