/* Problem -  */
/* By Sanjeet Boora */

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int check(int* arr, pair<int, vector<int> >*freq, int size) {
	for (int i = 1; i <= size; i++) {
		if (freq[i].first > 1) {
			for (int k = 0; k != freq[i].second.size(); k++) {
				for (int j = freq[i].second.size() - 1; j > k; j--) {
					if (j != k) {
						int a = freq[i].second[k], b = freq[i].second[j];
						if (freq[a].first > 0 && freq[b].first > 0) {
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		int size;
		int* arr;
		pair<int, vector<int> >*freq;
		cin >> size;
		arr = new int[size + 1];
		freq = new pair<int, vector<int> >[size + 1];
		for (int i = 1; i <= size; i++) {
			vector<int>v;
			freq[i] = make_pair(0, v);
		}
		for (int i = 1; i <= size; i++) {
			cin >> arr[i];
			freq[arr[i]].first++;
			freq[arr[i]].second.push_back(i);
		}
		if (check(arr, freq, size)) {
			cout << "Truly Happy" << endl;
		} else {
			cout << "Poor Chef" << endl;
		}
	}
	return 0;
}