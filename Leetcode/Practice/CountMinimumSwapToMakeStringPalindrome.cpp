//https://www.geeksforgeeks.org/count-minimum-swap-to-make-string-palindrome/
//https://leetcode.com/discuss/interview-question/351783/

#include <iostream>
using namespace std;
int palindrome(string str, int n){
    int count =0;
	for(int i=0; i< n/2; i++){
	    int left = i, right = n-i-1;
	    while(left < right){
	        if(str[left] == str[right]){
	            break;
	        }
	        else{
	            right--;
	        }
	    }
	    if(left == right){
	        return -1;
	    }
	    
	    for(int j = right; j<n-left-1; j++){
	        swap(str[j], str[j+1]);
	        count++;
	    }
	}
	return count;
}

int main() {
	string str;
	cin>>str;
	int n = str.length();
	cout<<palindrome(str, n)<<endl;
	return 0;
}
