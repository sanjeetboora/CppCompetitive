class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        vector<vector<int> > dp(len1 + 1, vector<int> (len2 + 1, 0));

        for (int i = len1; i >= 0; i--) {
            for (int j = len2; j >= 0; j--) {

                if (i == len1) {
                    dp[i][j] = len2 - j;
                }
                else if (j == len2) {
                    dp[i][j] = len1 - i;
                }
                else if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                }

                else {
                    dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1]));
                }
                //  cout<<dp[i][j]<<", ";
            }//cout<<endl;
        }
        return dp[0][0];
    }
};