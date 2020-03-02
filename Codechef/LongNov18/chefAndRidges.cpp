#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		ll a;
		cin >> a;
		ll b = pow(2, a);
		cout << 1 << " " << b<<" ";
	}
	return 0;
}