# include <iostream>
# include <stack>
# include <climits>

using namespace std;

bool isOperator(char ch) {
		
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
		return true;
	}
	return false;
}

bool isOperand(char ch) {
		
	if(ch >= '0' && ch <= '9') {
		return true;
	}

	return false;
}

int charToInt(char ch) {
		
	return (ch - '0');
}

int evaluatePrefixExpression(string expression) {
		
	stack<int> operands;
	for(int i = expression.size() - 1; i >= 0; i--) {
		
		if(isOperand(expression[i]) == true) {
			operands.push(charToInt(expression[i]));
		} else if(isOperator(expression[i]) == true) {
			int a = operands.top();
			operands.pop();
			int b = operands.top();
			operands.pop();

			switch(expression[i]) {
					
				case '+':
					operands.push(a + b);
					break;

				case '-':
					operands.push(a - b);
					break;

				case '*':
					operands.push(a * b);
					break;

				case '/':
					operands.push(a / b);
					break;
			}
		} else {
			cout << expression[i] << endl;
			cout << "Error : Character not recognized.\n\n";
			return INT_MIN;
		}
	}

	return operands.top();
}

int main(void) {
		
	string s;
	cin >> s;

	cout << evaluatePrefixExpression(s) << endl << endl;

	return 0;
}
