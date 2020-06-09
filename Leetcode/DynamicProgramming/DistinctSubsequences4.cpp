
class Solution {
public:

  int numDistinct(string s, string t) {
    int sSize = s.length() ;
    int tSize = t.length() ;
    long long int** dp = new long long int*[sSize + 1];

    for (int i = 0; i <= sSize; i++ ) {
      dp[i] = new long long int[tSize + 1];
    }

    for (int j = 0; j <= tSize; j++ ) {

      dp[sSize][j] = 0;

    }
    for (int i = 0; i <= sSize; i++ ) {
      dp[i][tSize] = 1;
    }


    for (int i = sSize - 1; i >= 0; i-- ) {
      for (int j = tSize - 1; j >= 0; j-- ) {
        dp[i][j] = dp[i + 1][j];
        if (s[i] == t[j]) {
          dp[i][j] += dp[i + 1][j + 1];
        }
      }
    }

    int ans = dp[0][0];
    return ans;
  }

};