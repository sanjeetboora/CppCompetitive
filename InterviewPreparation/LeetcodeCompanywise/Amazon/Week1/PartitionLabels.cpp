//https://leetcode.com/problems/partition-labels/
/* Time: O(N)  |  Space: O(1)  */
class Solution {
public:
    int arr[26] = {0};
    vector<int> partitionLabels(string S) {
        vector<int> res;
        if (S.length() == 0)return res;

        for (int i = S.length() - 1; i >= 0; i--) {
            if (i > arr[S[i] - 'a']) {
                arr[S[i] - 'a'] = i;
            }
        }
        int j = 0, k = 0;
        for (int i = 0; i < S.length(); i++) {
            if (arr[S[i] - 'a'] > j) {
                j = arr[S[i] - 'a'];
            }
            if (i == j) {
                if (res.empty()) {
                    res.push_back(j + 1);
                    k = j;
                }
                else {
                    res.push_back(j - k);
                    k = j;
                }
            }
        }
        return res;
    }
};