//https://leetcode.com/problems/reverse-string/
class Solution {
public:
	void reverseString(vector<char>& s) {

		int sz = s.length();

		if (sz <= 1) return;

		int i = 0, j = sz - 1;
		while (i < j) {
			swap(s[i], s[j]);
		}

	}
};