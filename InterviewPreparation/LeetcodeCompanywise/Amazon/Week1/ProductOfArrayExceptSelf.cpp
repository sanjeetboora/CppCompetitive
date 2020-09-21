//https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int sz = nums.size();
        if (!sz) return res;

        res.reserve(sz);
        res[sz - 1] = 1;
        for (int i = sz - 2; i >= 0; i--) { //right
            res[i] = res[i + 1] * nums[i + 1];
        }

        int left = 1;
        for (int i = 0; i < sz; i++) { //ans
            res.push_back(left * res[i]);
            left = left * nums[i];

        }
        return res;
    }
};