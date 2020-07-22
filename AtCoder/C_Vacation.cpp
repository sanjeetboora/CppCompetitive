#include<iostream>
using namespace std;
#define ll long long int
#define mod 1000000007
ll maxPoints(int n) {
	int a, b, c;

	ll prevA, prevB, prevC, nextA, nextB, nextC;
	cin >> a >> b >> c;
	prevA = a, prevB = b, prevC = c;

	for (int i = 2; i <= n; i++) {
		cin >> a >> b >> c;
		nextA = a + max(prevB, prevC);
		nextB = b + max(prevA, prevC);
		nextC = c + max(prevA, prevB);
		prevA = nextA;
		prevB = nextB;
		prevC = nextC;
	}
	return max(prevA, max(prevB, prevC));
}


int main() {
	int n;
	cin >> n;
	cout << maxPoints(n) << endl;

}