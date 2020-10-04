#include <bits/stdc++.h>
using namespace std;

int fib(int n) {

	if (n == 0 or n == 1) {
		return n;
	}

	int a = 0, b = 1, c = 1;
	while (c <= n) {
		a = b;
		b = c;
		c = a + b;
	}
	return b;

}

int main(int argc, char const *argv[])
{

	int n;
	cin >> n;

	vector<int> v;
	while (n > 0) {

		int x = fib(n);

		v.push_back(x);

		n = n - x;

	}

	for (int i = v.size() - 1;  i >= 0; i--) {
		cout << v[i] << ", ";
	}

	return 0;
}