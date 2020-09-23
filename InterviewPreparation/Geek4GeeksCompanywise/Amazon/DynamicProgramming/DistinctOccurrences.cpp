//https://practice.geeksforgeeks.org/problems/distinct-occurrences/1
//https://www.geeksforgeeks.org/count-distinct-occurrences-as-a-subsequence/

#define inf 1000000007
int subsequenceCount(string S, string T)
{
  //Your code here
  int m = S.length();
  int n = T.length();
  if (n > m) return 0;
  int dp[n + 1][m + 1];

  for (int i = 0; i <= n; i++) dp[i][0] = 0;
  for (int i = 0; i <= m; i++) dp[0][i] = 1;


  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (S[j - 1] != T[i - 1]) {
        dp[i][j] = dp[i][j - 1];
      }
      else {
        dp[i][j] = (dp[i - 1][j - 1] % inf + dp[i][j - 1] % inf) % inf;
      }

      // cout<<dp[i][j]<<", ";
    }
    //cout<<endl;
  }

  return dp[n][m];

}