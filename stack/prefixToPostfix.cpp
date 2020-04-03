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

string convertPrefixToPostfix(string prefixExpression) {
	
	string postfixExpression;
	stack<string> pendingOperands;

	for(int i = prefixExpression.length() - 1; i >= 0; i--) {
		
		if(isOperand(prefixExpression[i]) == true) {
			pendingOperands.push(string(1, prefixExpression[i]));
		}

		else if(isOperator(prefixExpression[i]) == true) {
			string expression;
			
			string a = pendingOperands.top();
			pendingOperands.pop();
			string b = pendingOperands.top();
			pendingOperands.pop();
			expression.append(a);
			expression.append(b);
			expression.append(string(1, prefixExpression[i]));

			pendingOperands.push(expression);
		}
	}

	return pendingOperands.top();
}

int main(void) {
		
	string s;
	cin >> s;

	cout << convertPrefixToPostfix(s) << endl << endl;

	return 0;
}
