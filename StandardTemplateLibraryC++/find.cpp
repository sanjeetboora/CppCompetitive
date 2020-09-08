#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(int);

	int key = 9;

	//find() return the address where key is found and if key is not found it will return address of nth position
	int index = find(arr, arr + n, key) - arr;

	if (index == n) {
		cout << key << " is not present" << endl;
	} else {
		cout << key << " is present" << endl;
	}



	return 0;
}