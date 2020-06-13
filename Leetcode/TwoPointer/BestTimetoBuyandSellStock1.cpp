class Solution {
public:
  int maxProfit(vector<int>& prices) {

    int len = prices.size();
    if (len == 0) {
      return 0;
    }
    int right = prices[len - 1];
    int ans = 0;

    for (int i = len - 2; i >= 0; i--) {
      ans = max(ans, right - prices[i]);
      if (prices[i] > right) {
        right = prices[i];
      }
    }
    return ans;
  }
};