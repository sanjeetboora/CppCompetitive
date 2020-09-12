//https://leetcode.com/problems/partition-labels/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int lastOcc[26] = {0};
        for (int i = 0; i < S.length(); i++) {
            lastOcc[S[i] - 'a'] = i;
        }
        int j = 0;
        int count = 0;
        for (int i = 0; i < S.length(); i++) {
            count++;
            if ( lastOcc[S[i] - 'a'] > j) {
                j =  lastOcc[S[i] - 'a'];
            }

            if ( i == j) {
                res.push_back(count);
                count = 0;
            }


        }
        return res;
    }
};