#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
	int arr[] = {1, 2, 4, 4, 5, 5, 5, 6};
	int n = sizeof(arr) / sizeof(int);

	int key = 3;

	//binary_search() return true or false depending upon if key is present in the array
	bool present = binary_search(arr, arr + n, key);

	if (present) {
		cout << key << " is present" << endl;
	} else {
		cout << key << " is not present" << endl;
	}


	//lower_bound() return the address of first element >= key

	auto it = lower_bound(arr, arr + n, key);
	int index = it - arr;
	cout << "lower boound of " << key << " is " << index << endl;


	//upper_bound() return the address of first element > key

	auto upit = upper_bound(arr, arr + n, key);
	int upindex = upit - arr;
	cout << "upper boound of " << key << " is " << upindex << endl;


	//freq of an element
	int freq = upit - it;
	cout << "freq of " << key << " is " << freq << endl;



	return 0;
}