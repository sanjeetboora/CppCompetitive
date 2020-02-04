//https://www.geeksforgeeks.org/count-pairs-with-given-sum/
#include<bits/stdc++.h>
using namespace std;

void targetSumPairs(int *arr, int size, int target) {
	int pairs = 0;
	int tempArr[10000] = {0};
	for (int i = 0; i < size; ++i)
	{
		tempArr[arr[i]]++;
		cout << tempArr[arr[i]] << endl;
	}

	for (int i = 0; i < size ; ++i)
	{
		if (tempArr[target - arr[i]] > 0) {
			pairs += 1;
		}

	}
	cout << pairs / 2 << endl;
}

int main(int argc, char const *argv[])
{
	int size, target;
	cin >> size >> target;
	int* arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}
	targetSumPairs(arr, size, target);

	return 0;
}