#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	int n, k;
	cin >> n >> k;
	k=k%n;
	char* arr = new char[n];
	char* temp = new char[n];
	cin >> arr;
	cout << arr << endl;
	// copy elements to temp array
	for (int i = 0; i < k; ++i)
	{
		temp[i] = arr[i];
	}
	// shift rest of the elements of original array
	for (int i = 0; i < n - k; ++i)
	{
		arr[i] = arr[i + k];
	}
	// copy elements from temp array to original array
	for (int i = 0; i < k; ++i)
	{
		arr[n-k+i] = temp[i];
	}
	cout << arr << endl;

	return 0;
}