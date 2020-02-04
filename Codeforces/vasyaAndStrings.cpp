//https://codeforces.com/problemset/problem/676/C
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;

	string str;
	cin >> str;

	int count[2] = {0, 0};
	int left = 0, result = 0;

	for (int i = 0; i < n; ++i)
	{
		count[str[i] - 'a']++;

		if(min(count[0],count[1])>k){
			count[str[left] - 'a']--;
			left++;
		}
		else{
			result++;
		}

	}
	cout<<result<<endl;


	return 0;
}