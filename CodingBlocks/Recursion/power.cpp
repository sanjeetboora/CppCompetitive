#include<bits/stdc++.h>
using namespace std;

int power(int m, int n) {
	if (n == 0) {
		return 1;
	}

	int result = m * power(m, n - 1);
	return result;
}

int main(int argc, char const *argv[])
{	int m, n;
	cin >> m >> n;
	cout << power(m, n) << endl;

	return 0;

}