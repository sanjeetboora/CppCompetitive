//https://leetcode.com/problems/group-anagrams/

/*  Time: O(NKlogK)  |   Space: O(NK)   */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        int sz = strs.size();
        if (!sz) return ans;

        unordered_map<string, vector<string> >mp;

        for (string s : strs) {
            string w = s;
            sort(s.begin(), s.end());
            mp[s].push_back(w);
        }

        for (auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};


/*  Time: O(NK)  |   Space: O(NK)   */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        int sz = strs.size();
        if (!sz) return ans;

        unordered_map<string, vector<string> >mp;

        for (string s : strs) {
            int arr[26] = {0};
            string w = "";
            for (char ch : s) {
                arr[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                int j = arr[i];
                while (j--) {
                    w += (char)i + 'a';
                }
            }
            mp[w].push_back(s);
        }

        for (auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};