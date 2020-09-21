/*   https://leetcode.com/problems/coin-change/submissions/  */
/*  Top-down DP  */
class Solution {
public:

    int mincoins(vector<int>& coins, int* dp, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;

        if (dp[amount] != 0) return dp[amount];

        int mini = INT_MAX;
        for (int c : coins) {
            int res = mincoins(coins, dp, amount - c);
            if (res >= 0 and res < mini) {
                mini = 1 + res;
            }
        }
        dp[amount] = (mini == INT_MAX) ? -1 : mini;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;

        int n = coins.size();
        int dp[10000] = {0};
        int coin = mincoins(coins, dp, amount);
        return coin;
    }
};


/*  Bottom-up DP  */
class Solution {
public:

    int mincoins(vector<int>& coins, int* dp, int amount) {

        for (int i = 1; i <= amount; i++) {
            dp[i] = amount + 1;
        }
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;

        int dp[10000];
        int coin = mincoins(coins, dp, amount);
        return coin;
    }
};