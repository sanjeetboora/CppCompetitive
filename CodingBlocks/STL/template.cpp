#include<bits/stdc++.h>
using namespace std;

//generic programming
template<class T>
void printArray(T* arr, int n){
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<", ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	char arr[10] = {'1','2','3','4','5'};
	int n = 10;
	printArray(arr,n);

	return 0;
}