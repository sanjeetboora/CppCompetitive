//https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0

#include <iostream>
using namespace std;

int countSubseq(string s) {

	int aCount = 0, bCount = 0, cCount = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a') {
			aCount = (2 * aCount) + 1;
		}
		else if (s[i] == 'b') {
			bCount = (2 * bCount) + aCount;
		}
		else if (s[i] == 'c') {
			cCount = (2 * cCount) + bCount;
		}
	}
	return cCount;

}

int main() {
	//code
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		cout << countSubseq(s) << endl;
	}
	return 0;
}