/* Problem - https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/ */
/* By Sanjeet Boora */

// #include <bits/stdc++.h>
// using namespace std;

// void uniqueElement(vector<int> v, int low, int high) {
// 	if (low > high) {
// 		return;
// 	}
// 	if (low == high) {
// 		cout << v[low] << endl;
// 		return;
// 	}
// 	while (low < high) {
// 		int mid = low + (high - low) / 2;
// 		if (mid & 1) {
// 			if (v[mid] == v[mid - 1]) {
// 				uniqueElement(v, mid + 1, high);
// 			}
// 			else {
// 				uniqueElement(v, low, mid - 1);
// 			}
// 		}

// 		else {
// 			if (v[mid] == v[mid + 1]) {
// 				uniqueElement(v, mid + 2, high);
// 			}
// 			else {
// 				uniqueElement(v, low, mid);
// 			}
// 		}
// 	}

// }


// int main(int argc, char const *argv[])
// {
// 	vector<int> v = {1, 1, 1, 1, 100};
// 	int n = v.size();
// 	uniqueElement(v, 0, n - 1);
// 	return 0;
// }



#include <iostream>
using namespace std;
int uniqueElement(int* arr, int n) {
	int start = 0,  end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1] ) {
			return mid;
		}
		// when mid is even

		if ( mid % 2 == 0) {
			if (arr[mid] == arr[mid + 1]) {
				start = mid + 1; //search in right
			}
			else {
				end = mid - 1;//search in left
			}
		}
		// when mid is odd
		else {
			if (arr[mid] == arr[mid - 1]) {
				start = mid + 1; //search in right
			}
			else {
				end = mid - 1;//search in left
			}
		}

	}
	return -1;
}

int main(int argc, char const *argv[])
{
	// int arr[20] = {1, 1, 2, 2, 4, 4, 5, 5, 6, 7, 7};
	// int n = 11;
	int arr[4] = {1, 1, 1, 1};
	int n = 4;
	int idx = uniqueElement(arr, n);
	cout << arr[idx	] << endl;

	return 0;
}
