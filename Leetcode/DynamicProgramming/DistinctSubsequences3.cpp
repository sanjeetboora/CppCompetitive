
class Solution {
public:


    int subseq(string s, string t, int i, int j, int sSize, int tSize, int** dp) {
        if (i == sSize or j == tSize or sSize - i < tSize - j) {
            return j == tSize ? 1 : 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = subseq(s, t, i + 1, j, sSize, tSize, dp);
        if (s[i] == t[j]) {
            ans  +=  subseq(s, t, i + 1, j + 1, sSize, tSize, dp);
        }
        dp[i][j] = ans;
        return dp[i][j];

    }

    int numDistinct(string s, string t) {
        int sSize = s.length() ;
        int tSize = t.length() ;
        int** dp = new int*[sSize + 1];
        for (int i = 0; i <= sSize; i++ ) {
            dp[i] = new int[tSize + 1];
        }
        for (int i = 0; i <= sSize; i++ ) {
            for (int j = 0; j <= tSize; j++ ) {
                dp[i][j] = -1;
                dp[sSize][j] = 0;
                dp[i][tSize] = 1;
            }
        }

        return subseq(s, t, 0, 0, sSize, tSize, dp);
    }
};