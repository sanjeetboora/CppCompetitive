// Check if there is a subarray with sum zero.
#include<bits/stdc++.h>
using namespace std;
bool subArrayExists(int* arr, int n) {
	unordered_map<int, int> mp;
	int prefixSum = 0;
	for (int i = 0; i < n; ++i)
	{
		prefixSum += arr[i];
		if (mp.count(prefixSum) and mp[prefixSum] != i) {
			cout << mp[prefixSum] << ", " << i << endl;
			return true;
		}
		mp[prefixSum] = i;
	}
	return false;
}

int main(int argc, char const *argv[]) {
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 6;
	int arr[10] = {2, 3, 1, -2, -2};
	if (subArrayExists(arr, n)) {
		cout << "subarray with sum zero exists" << endl;
	}
	else {
		cout << "subarray with sum zero doesn't exists" << endl;
	}

	return 0;
}

