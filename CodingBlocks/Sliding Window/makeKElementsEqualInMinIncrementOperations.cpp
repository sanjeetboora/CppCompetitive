#include<bits/stdc++.h>
using namespace std;

void sortArr(int *arr, int size) {

	sort(arr, arr+size);
	int low =0, mid=0, high=size-1;

	while(mid <= high){

		if(arr[mid] == 0){
			swap(arr[low], arr[mid]);
			low++;
			mid++;
		}
		else if(arr[mid] == 1){
			mid++;
		}
		else{
			swap(arr[mid], arr[high]);
			high--;
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