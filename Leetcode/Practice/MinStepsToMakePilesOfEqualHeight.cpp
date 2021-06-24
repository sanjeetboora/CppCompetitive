//https://leetcode.com/discuss/interview-question/364618/

#include <bits/stdc++.h>
using namespace std;

int reductionSteps(int* arr, int n){
    sort(arr, arr+n, greater<int>());
    int count = 0;
    for(int i=1; i<n; i++){
        if(arr[i] != arr[i-1]){
            count += i;
        }
    }
    return count;
}

int main() {
	int arr[20] = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4};
	int n = 10;
	cout<<reductionSteps(arr, n)<<endl;
	return 0;
}
