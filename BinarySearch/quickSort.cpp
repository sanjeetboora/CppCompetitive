/* Problem -  */
/* By Sanjeet Boora */

#include <bits/stdc++.h>
using namespace std;

void printArray(int* arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int partition(int* arr, int st, int end) {
	int pivot = arr[end];

	int i = st - 1, j = st;
	while (j < end) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
		j++;
	}
	i++;
	swap(arr[end], arr[i]);
	return i;
}

void quickSort(int* arr, int st, int end) {
	if (st >= end) {
		return;
	}
	int pivotIdx = partition(arr, st, end);

	quickSort(arr, st, pivotIdx - 1); //left
	quickSort(arr, pivotIdx + 1, end); //right
}



int main(int argc, char const *argv[])
{
	int arr[10] = {2, 3, 1, 6, 4, 5, 0};
	int n = 7;
	printArray(arr, n);
	quickSort(arr, 0, n - 1);
	printArray(arr, n);

	return 0;
}