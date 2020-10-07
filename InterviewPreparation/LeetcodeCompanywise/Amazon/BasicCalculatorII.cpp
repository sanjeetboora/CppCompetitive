//https://leetcode.com/problems/basic-calculator-ii/

class Solution {
public:
	int calculate(string s) {

		istringstream in('+' + s + '+');

		int result = 0, term = 0;
		char op;

		while (in >> op) {
			if (op == '+' or op == '-') {
				result += term;
				in >> term;
				term = term * ((op == '+') ? 1 : -1);

			}
			else if (op == '*' or op == '/') {
				int n;
				in >> n;
				term = (op == '*') ? term * n : term / n;
			}

		}
		return result;
	}
};