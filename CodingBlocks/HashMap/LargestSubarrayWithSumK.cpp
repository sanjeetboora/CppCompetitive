// Largest subarray with sum k.
#include<bits/stdc++.h>
using namespace std;
int subArrayLength(int* arr, int n, int k) {
	unordered_map<int, int> mp;
	int prefixSum = 0, len = 0;
	for (int i = 0; i < n; ++i)
	{
		prefixSum += arr[i];

		if (prefixSum == k) {
			len = max(i + 1, len);
		}
		if (mp.count(prefixSum - k)) {
			int curr = i - mp[prefixSum - k];
			len = max(curr, len);
		}
		else {
			mp[prefixSum] = i;
		}

	}
	return len;
}

int main(int argc, char const *argv[]) {
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 6, k = 3;
	int arr[10] = {2, 1, 2, 0, -1, 2};
	int len = subArrayLength(arr, n, k);

	cout << "max length of subarray with sum zero is " << len << endl;


	return 0;
}

