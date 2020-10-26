/* Problem -  */
/* By Sanjeet Boora */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int>countMap;
long long int dig_sum(long long int num) {
	long long int sum = 0;
	while (num != 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
void minsum_opr(long long int N, long long int D, long long int opr, int calls, long long int arr[2]) {
	if (calls > 20) {
		return;
	}
	long long int curr_N = dig_sum(N);
	long long int curr_opr = N > 9 ? 1 : 0;
	if (countMap.find(curr_N) == countMap.end()) {
		countMap.insert(make_pair(curr_N, (opr + curr_opr)));
		if (curr_N <= arr[0]) {
			if (curr_N == arr[0]) {
				arr[1] = arr[1] < (opr + curr_opr) ? arr[1] : (opr + curr_opr);
			}
			else {
				arr[0] = curr_N;
				arr[1] = opr + curr_opr;
			}
		}
		if (curr_N <= arr[0]) {
			if (curr_N == arr[0]) {
				arr[1] = arr[1] < (opr + curr_opr) ? arr[1] : (opr + curr_opr);
			}
			else {
				arr[0] = curr_N;
				arr[1] = opr + curr_opr;
			}
		}
		minsum_opr(N + D, D, opr + 1, calls + 1, arr);
		minsum_opr(curr_N, D, opr + curr_opr, calls + 1, arr);
		countMap.erase(curr_N);
	}
	else {
		if ((countMap.find(curr_N)->second) > (opr + curr_opr)) {
			countMap.find(curr_N)->second = opr + curr_opr;
		}
		if (curr_N <= arr[0]) {
			if (curr_N == arr[0]) {
				arr[1] = arr[1] < (opr) ? arr[1] : (opr);
			}
			else {
				arr[0] = curr_N;
				arr[1] = opr;

			}
		}
	}

}
int main(int argc, char const *argv[])
{	long long int test;
	cin >> test;
	for (long long int i = 0; i < test; i++)
	{
		long long int N, D;
		long long int arr[2];
		arr[0] = INT_MAX;
		arr[1] = INT_MAX;
		countMap.clear();
		cin >> N >> D;
		minsum_opr(N, D, 0, 0, arr);
		map <long long int, long long int> :: iterator it;
		long long int min = INT_MAX, minc = INT_MAX;
		cout << arr[0] << " " << arr[1] << endl;
	}

	return 0;
}