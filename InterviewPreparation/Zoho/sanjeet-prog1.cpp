#include <bits/stdc++.h>
using namespace std;

int maxSum(int n, int* arr) {
	sort(arr, arr + n);
	int sum = arr[n - 1] + arr[n - 2] + arr[n - 3];
	return sum;
}

int main(int argc, char const *argv[])
{

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << maxSum(n, arr) << endl;

	return 0;
}