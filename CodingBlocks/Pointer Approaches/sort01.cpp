//https://hack.codingblocks.com/app/practice/1/p/105
#include<bits/stdc++.h>
using namespace std;

void sortArr(int *arr, int size) {

	sort(arr, arr + size);
	int i = 0, j = size - 1;
	while (i < j)
	{
		if(arr[i] == 1){
			swap(arr[i], arr[j]);
			j--;
		}
		else if(arr[i] == 0){
			i++;
		}
	}
	for (int i = 0; i < size; ++i)
	{
		cout<< arr[i]<<" ";
	}

}

int main(int argc, char const *argv[])
{
	int size;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}
	sortArr(arr, size);

	return 0;
}