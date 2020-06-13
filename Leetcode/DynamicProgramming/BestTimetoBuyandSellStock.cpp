class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int len = prices.size();
        if (len == 0) {
            return 0;
        }
        vector<int> leftMin(len, 0);
        leftMin[0] = prices[0];
        for (int i = 1; i < len; i++) {
            leftMin[i] = min(leftMin[i - 1], prices[i]);
        }
        int ans = 0;
        for (int i = len - 1; i >= 0; i--) {
            ans = max(ans, prices[i] - leftMin[i]);
        }
        return ans;
    }
};