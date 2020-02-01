//https://hack.codingblocks.com/app/practice/1/p/211
#include<bits/stdc++.h>
using namespace std;

void targetSumPairs(int *arr, int size, int target) {

	sort(arr, arr + size);
	int i = 0, j = size - 1;
	while (i < j)
	{
		if (arr[i] + arr[j] == target) {
			cout << arr[i] << " and " << arr[j] << endl;
			i++;
			j--;
		}
		else if (arr[i] + arr[j] > target) {
			j--;
		}
		else {
			i++;
		}
	}

}

int main(int argc, char const *argv[])
{
	int size, target;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}
	cin >> target;
	targetSumPairs(arr, size, target);

	return 0;
}