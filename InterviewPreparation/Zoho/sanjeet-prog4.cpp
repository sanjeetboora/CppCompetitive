#include <bits/stdc++.h>
using namespace std;

void moveZeroToEnd(int n, int* arr) {
	int nonZeroBefore = 0;
	int curr = 0;

	while (curr < n) {
		if (arr[curr] != 0) {
			swap(arr[nonZeroBefore], arr[curr]);
			nonZeroBefore++;
		}
		curr++;
	}
}

int main(int argc, char const *argv[])
{

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	moveZeroToEnd(n, arr)
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}

	return 0;
}