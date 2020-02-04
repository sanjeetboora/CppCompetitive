//https://www.geeksforgeeks.org/find-three-closest-elements-from-given-three-sorted-arrays/
#include<bits/stdc++.h>
using namespace std;
void closestElements(int* arr1, int* arr2, int* arr3, int size1, int size2, int size3) {

	int i = 0, j = 0, k = 0, minDiff = INT_MAX, resi, resj, resk;

	while (i < size1 && j < size2 && k < size3) {
		int minEle = min(arr1[i], min(arr2[j], arr3[k]));
		int maxEle = max(arr1[i], max(arr2[j], arr3[k]));
		int currDiff = maxEle - minEle;
		if (minDiff > currDiff) {
			minDiff = currDiff;
			resi = i;
			resj = j;
			resk = k;
		}
		if (minDiff == 0) {
			break;
		}
		if (arr1[i] == minEle) {
			i++;
		}
		else if (arr2[j] == minEle) {
			j++;
		}
		else {
			k++;
		}
	}

	cout << arr1[resi] << ", " << arr2[resj] << ", " << arr3[resk] << endl;
}


int main(int argc, char const *argv[])
{
	int size1, size2, size3;
	cin >> size1 >> size2 >> size3;
	int* arr1 = new int[size1];
	int* arr2 = new int[size2];
	int* arr3 = new int[size3];
	for (int i = 0; i < size1; ++i)
	{
		cin >> arr1[i];
	}
	for (int i = 0; i < size2; ++i)
	{
		cin >> arr2[i];
	}
	for (int i = 0; i < size3; ++i)
	{
		cin >> arr3[i];
	}

	closestElements(arr1, arr2, arr3, size1, size2, size3);

	return 0;
}