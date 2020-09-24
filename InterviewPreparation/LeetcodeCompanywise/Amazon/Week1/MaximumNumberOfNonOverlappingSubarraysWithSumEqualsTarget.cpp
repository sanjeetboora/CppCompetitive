//https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/


/*  Time: O(N) |  Space: O(1)   */

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int res = 0;
        int sz = nums.size();
        if (!sz) return res;

        unordered_set<int> st;
        st.insert(0);
        int prefix = 0;
        for (int i = 0; i < sz; i++) {
            prefix += nums[i];

            if (st.find(prefix - target) != st.end()) {
                res++;
                st.clear();
                prefix = 0;
            }
            st.insert(prefix);
        }
        return res;
    }
};