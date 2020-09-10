//https://leetcode.com/discuss/interview-question/808348/
class Solution {
public:
    int maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        int i = 0;
        dq.push_back(i++);
        while (i < k) {
            while (dq.size() > 0 and nums[dq.back()] > nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            i++;
        }
        res.push_back(nums[dq.front()]);

        while (i < nums.size()) {
            if (dq.front() <= i - k) {
                dq.pop_front();
            }
            while (dq.size() > 0 and nums[dq.back()] > nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i++);
            res.push_back(nums[dq.front()]);
        }

        int ans = *max_element(res.begin(), res.end());
        return ans;
    }
};