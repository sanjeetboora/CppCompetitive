//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> freqMap;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            freqMap[nums[i]] = i;
        }
        
        
        for(int i=0; i<nums.size(); i++){
            if(freqMap.count(target-nums[i]) and freqMap[target-nums[i]] != i){
                return {i, freqMap[target-nums[i]]};
            }   
        }
        return result;
    }
};
