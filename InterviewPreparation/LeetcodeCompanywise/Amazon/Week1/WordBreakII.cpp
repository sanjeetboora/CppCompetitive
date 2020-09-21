//https://leetcode.com/problems/word-break-ii/

class Solution {
public:
	unordered_map<string, vector<string> >mp;
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		if (mp.count(s) != 0) return mp[s];
		vector<string> res;

		for (string word : wordDict) {
			if (s.substr(0, word.length()) == word) {

				if (word.length() == s.length()) {
					res.push_back(word);
				}
				else {
					vector<string> v = wordBreak(s.substr(word.length()), wordDict);
					for (string x : v) {
						res.push_back(word + " " + x);
					}
				}
			}
		}
		mp[s] = res;
		return res;
	}
};