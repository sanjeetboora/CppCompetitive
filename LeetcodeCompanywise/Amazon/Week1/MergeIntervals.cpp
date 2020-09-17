/* https://leetcode.com/problems/merge-intervals/  */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        vector<vector<int>> res;
        if (!sz) return res;

        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]);
        for (int i = 1; i < sz; i++) {
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};