/* Problem - https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650 */
//https://www.topcoder.com/community/competitive-programming/tutorials/binary-search/
/* By Sanjeet Boora */

#include <bits/stdc++.h>
using namespace std;

int workLoad(vector<int> folders, int workers) {
	int n = folders.size();
	int low = *max_element(folders.begin(), folders.end());
	int high = accumulate(folders.begin(), folders.end(), 0);

	while (low < high) {
		int mid = low + (high - low) / 2;
		int w = 1, load = 0;
		for (int i = 0; i < n; ++i)
		{
			if (load + folders[i] <= mid) {
				load += folders[i];
			}
			else {
				load = folders[i];
				w++;
			}
		}
		if (w <= workers) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}


int main(int argc, char const *argv[])
{

	int workers = 5;
	vector<int> folders = {1, 1, 1, 1, 100};
	cout << workLoad(folders, workers) << endl;
	return 0;
}