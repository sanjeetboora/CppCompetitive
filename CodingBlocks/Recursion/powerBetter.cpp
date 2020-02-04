#include<bits/stdc++.h>
using namespace std;

int power(int m, int n) {
	if (n == 0) {
		return 1;
	}

	int smallerResult = power(m, n / 2);
	int result = smallerResult * smallerResult;
	if (n & 1) {
		result = m * result;
	}

	return result;
}

int main(int argc, char const *argv[])
{	int m, n;
	cin >> m >> n;
	cout << power(m, n) << endl;

	return 0;

}