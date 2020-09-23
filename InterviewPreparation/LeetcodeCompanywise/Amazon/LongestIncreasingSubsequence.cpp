//https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> temp;
        temp.push_back(nums[0]);

        int maxlen = 1;

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            vector<int>::iterator ad = lower_bound(temp.begin(), temp.end(), x);

            if (ad == temp.end()) {
                temp.push_back(x);
                maxlen = max((int)temp.size(), maxlen);
            }
            else {
                *ad = x;
            }
        }
        return maxlen;
    }
};