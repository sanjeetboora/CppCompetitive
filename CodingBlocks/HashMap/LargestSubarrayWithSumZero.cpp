// Largest subarray with sum zero.
#include<bits/stdc++.h>
using namespace std;
int subArrayLength(int* arr, int n) {
	unordered_map<int, int> mp;
	int prefixSum = 0, len = 0;
	for (int i = 0; i < n; ++i)
	{
		prefixSum += arr[i];
		if (arr[i] == 0 and len == 0) {
			len = 1;
		}
		if (prefixSum == 0) {
			len = max(i + 1, len);
		}
		if (mp.count(prefixSum)) {
			int curr = i - mp[prefixSum];
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
	int n = 6;
	int arr[10] = {0, -1, 2, -1, 0, 1};
	int len = subArrayLength(arr, n);

	cout << "max length of subarray with sum zero is " << len << endl;


	return 0;
}

