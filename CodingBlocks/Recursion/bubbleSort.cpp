#include<bits/stdc++.h>
using namespace std;
void bubbleSort1(int* arr, int n) {
	if (n == 1) {
		return;
	}

	for (int i = 0; i < n - 1 ; ++i)
	{
		if (arr[i] > arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
		}
	}
	bubbleSort1(arr, n - 1);

}
void bubbleSort2(int* arr, int n, int i) {
	if (n == 1) {
		return;
	}
	if (i == n - 1) {
		bubbleSort2(arr, n - 1, 0);
		return;
	}

	if (arr[i] > arr[i + 1]) {
		swap(arr[i], arr[i + 1]);
	}
	bubbleSort2(arr, n, i + 1);

}


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	//bubbleSort1(arr, n);
	bubbleSort2(arr, n, 0);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;

	return 0;
}