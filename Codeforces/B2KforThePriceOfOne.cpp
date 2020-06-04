//https://codeforces.com/problemset/problem/1282/B2

#include <bits/stdc++.h>
using namespace  std;
#define ll long long int

ll maxGoods(int* arr, ll n, ll p, ll k) {
	ll dp[200010] = {0};
	sort(arr, arr + n);
	ll ans = 0;

	for (ll i = 0; i < n; ++i)
	{
		if (i < k - 1) {
			dp[i] = arr[i] + (i == 0 ? 0 : dp[i - 1]);
		}
		else {
			dp[i] = arr[i] + (i == k - 1 ? 0 : dp[i - k]);
		}
		if (dp[i] <= p) {
			ans = i + 1;
		}
	}
	return ans;
}



int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--) {
		ll n, p, k;
		cin >> n >> p >> k;
		int arr[n];
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << maxGoods(arr, n, p, k) << endl;

	}



	return 0;
}