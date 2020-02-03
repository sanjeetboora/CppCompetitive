#include<bits/stdc++.h>
using namespace std;
bool isSorted(int* arr, int n) {
	if (n == 1) {
		return true;
	}
	cout << arr[0] << ", " << endl;
	if ( arr[0] <= arr[1] && isSorted(arr + 1, n - 1)) {
		return true;
	}
	else {
		return false;
	}

}
int main(int argc, char const *argv[])
{	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	if (isSorted(arr, n) == true) {
		cout << "array is sorted" << endl;
	}
	else {
		cout << "array is not sorted" << endl;
	}

	return 0;
}