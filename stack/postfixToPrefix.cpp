# include <iostream>
# include <string>
# include <stack>
using namespace std;

bool isOperand(char ch) {
		
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		return true;
	}
	return false;
}

bool isOperator(char ch) {
	
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
		return true;
	}
	return false;
}

string convertPostfixToPrefix(string postfixExpression) {
		
	string prefixExpression;
	stack<string> pendingOperands;

	for(int i = 0; i < postfixExpression.length(); i++) {
		
		if(isOperand(postfixExpression[i]) == true) {
			pendingOperands.push(string(1, postfixExpression[i]));
		}

		else if(isOperator(postfixExpression[i]) == true) {
			string expression;

			expression.append(string(1, postfixExpression[i]));
			string b = pendingOperands.top();
			pendingOperands.pop();
			string a = pendingOperands.top();
			pendingOperands.pop();
			expression.append(a);
			expression.append(b);

			pendingOperands.push(expression);
		}
	}

	return pendingOperands.top();
}

int main(void) {
		
	string s;
	cout << "\nEnter a valid postfix expression(don't use parentheses) : ";
	cin >> s;

	cout << convertPostfixToPrefix(s) << endl;
}
