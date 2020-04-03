# include <iostream>
# include <climits>
# include <stack>
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
	
	return ch - '0';
}

int evaluatePostfixExpression(string expression) {
		
	int value = 0;
	stack<int> operands;

	for(int i = 0; i < expression.size(); i++) {
			
		if(isOperand(expression[i]) == true) {
			operands.push(charToInt(expression[i]));
		} else if(isOperator(expression[i]) == true) {
			int a = operands.top();
			operands.pop();
			int b = operands.top();
			operands.pop();

			switch(expression[i]) {
				case '+':
					operands.push(b + a);
					break;

				case '-':
					operands.push(b - a);
					break;

				case '*':
					operands.push(b * a);
					break;

				case '/':
					operands.push(b / a);
					break;
			}
		} else {
			cout << "Error : Character not recognized.";
			return INT_MIN;
		}
	}

	return operands.top();
}

int main(void) {
		
	string s;
	cin >> s;

	cout << evaluatePostfixExpression(s) << endl << endl;

	return 0;
}
