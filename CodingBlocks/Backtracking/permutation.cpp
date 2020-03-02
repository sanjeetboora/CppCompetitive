#include<bits/stdc++.h>
using namespace std;
void permutations(char* arr, int i) {
	if(arr[i] == '\0'){
		cout<<arr<<endl;
		return;
	}

	for (int j = i; arr[j] != '\0'; j++)
	{
		swap(arr[i], arr[j]);
		permutations(arr, i+1);
		swap(arr[i],arr[j]);
	}
}


int main(int argc, char const *argv[])
{
	char arr[100];
	cin >> arr;
	permutations(arr, 0);
	return 0;
}