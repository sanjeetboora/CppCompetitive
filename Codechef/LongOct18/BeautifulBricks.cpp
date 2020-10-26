/* Problem -  */
/* By Sanjeet Boora */

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll power(ll num, ll pow, ll m)
{
	ll calc = 1;
	num = num % m;
	while (pow > 0)
	{
		if (pow & 1) {
			ll b = ((calc % m) * (num % m)) % m;
			calc = b;
		}
		pow = pow >> 1;
		ll a = (num % m) * (num % m) % m;
		num = a;
	}
	return calc;
}

ll moduloInverse(ll num, ll m)
{
	return power(num, m - 2, m);

}

ll Coeff(ll n, ll k)
{
	ll op = 1;
	ll m = 1000000007;
	for (ll i = 0; i < k; ++i)
	{
		op = ((op % m) * ((n - i) % m)) % m;
		//op/=i+1;
		ll i_inverse = moduloInverse(i + 1, m);
		op = (op * i_inverse) % m;
	}
	return op;
}


int main(int argc, char const *argv[])
{
	ll test;
	cin >> test;
	for (ll k = 0; k < test; k++)
	{
		ll N, K;
		cin >> N >> K;
		if (K > N) {
			cout << 0 << endl;
			continue;
		}
		else if (K == N) {
			cout << 2 << endl;
		}
		else {

			ll m = 1000000007;
			//N = N - K + 1;
			ll sum = 0;
			for (ll i = 0; i <= K - 1; i++) {
				ll prod = power(2, i + 1, m);
				ll a = sum;
				ll temp = 1;
				temp = (temp * prod) % m;
				temp = (temp * Coeff(N - K + 1, i + 1)) % m;
				temp = (temp * Coeff(K - 1, i)) % m;
				ll b = temp;
				sum = ((a % m) + (b % m)) % m;

			}
			cout << sum << endl;
		}
	}
	return 0;
}





