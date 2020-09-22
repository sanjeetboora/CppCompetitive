/*  https://leetcode.com/problems/jump-game/  */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (!nums.size()) return false;

        bool dp[100000];

        for (int i = 0; i < nums.size(); i++) {
            dp[i] = false;
        }
        dp[0] = true;
        for (int i = 0; i < nums.size() - 1 and dp[i] == true; i++) {
            if (i + nums[i] < nums.size() and !dp[i + nums[i]]) {
                for (int j = i; j <= i + nums[i] and j < nums.size(); j++) {
                    dp[j] = true;

                }
            }
            else if (!dp[nums.size() - 1]) {
                for (int j = i; j <= i + nums[i] and j < nums.size(); j++) {
                    dp[j] = true;

                }
            }

        }
        return dp[nums.size() - 1];
    }
};

//Greedy

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (!nums.size()) return false;


        int lastpos = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (lastpos < i) {
                return false;
            }
            lastpos = max(lastpos, i + nums[i]);
            if (lastpos >= nums.size() - 1) {
                return true;
            }
        }
        if (lastpos >= nums.size() - 1) {
            return true;
        }
        return false;
    }
};