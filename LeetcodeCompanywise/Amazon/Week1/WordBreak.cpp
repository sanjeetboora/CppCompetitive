//https://leetcode.com/problems/word-break/

/*  O(N^2) with O(N) extra space  */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int sz = s.length();
        unordered_set<string> st;
        for (string s : wordDict) {
            st.insert(s);
        }
        bool dp[sz + 1];

        memset(dp, false, sizeof(dp));
        dp[sz] = true;

        for (int i = sz - 1; i >= 0; i--) {
            string word = "";
            for (int j = i; j < sz; j++) {
                word += s[j];
                if (st.find(word) != st.end()) {
                    if (dp[j + 1]) {
                        dp[i] = true;
                        break;
                    }
                }
            }

        }

        return dp[0];
    }
};