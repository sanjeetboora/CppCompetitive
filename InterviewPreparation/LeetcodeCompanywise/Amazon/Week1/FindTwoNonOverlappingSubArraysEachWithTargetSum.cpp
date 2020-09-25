//https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sz = arr.size();
        if (!arr.size()) return -1;

        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i = 0; i < sz; i++) {
            sum += arr[i];
            mp[sum] = i;
        }
        int res = INT_MAX, leftSize = INT_MAX;
        sum = 0;
        for (int i = 0; i < sz; i++) {
            sum += arr[i];
            if (mp.count(sum - target)) {
                leftSize = min(leftSize, i - mp[sum - target]);
            }

            if (mp.count(sum + target) and leftSize < INT_MAX) {
                res = min(res, leftSize + mp[sum + target] - i);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};