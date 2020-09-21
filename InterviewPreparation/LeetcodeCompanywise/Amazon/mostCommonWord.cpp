//https://leetcode.com/problems/most-common-word/

class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {

		unordered_set<string> ban(banned.begin(), banned.end());

		int i = 0;
		string result;
		int maxFreq = 0;
		unordered_map<string, int> mp;
		while (i < paragraph.length()) {

			if (isalpha(paragraph[i])) {
				string curr = "";
				while (i < paragraph.length() and isalpha(paragraph[i])) {
					curr += string(1, tolower(paragraph[i]));
					i++;
				}

				if (ban.find(curr) == ban.end()) {

					mp[curr]++;

					if (maxFreq < mp[curr]) {
						maxFreq = mp[curr];
						result = curr;
					}
				}
			}
			else {
				i++;
			}
		}
		return result;
	}
};