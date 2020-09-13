//https://leetcode.com/problems/two-sum/
//https://leetcode.com/discuss/interview-question/356960
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    vector<int> res;
    for (int x = 0; x < nums.size(); x++) {
      mp[nums[x]] = x;
      cout << nums[x] << "->" << mp[nums[x]] << endl;
    }
    for (int x = 0; x < nums.size(); x++) {
      if (mp.count(target - nums[x]) and mp[target - nums[x]] != x) {
        res.push_back(x);
        res.push_back(mp[target - nums[x]]);
        sort(res.begin(), res.end());
        return res;
      }
    }
    return res;
  }
};