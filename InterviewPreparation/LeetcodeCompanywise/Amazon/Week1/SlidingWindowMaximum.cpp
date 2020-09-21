/*  https://leetcode.com/problems/sliding-window-maximum/   */


//using deque | Time: O(N) | Space: O(K)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        int sz = nums.size();
        if (!sz) return res;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() and nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        for (int i = k; i < sz; i++) {
            while (!dq.empty() and dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() and nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};