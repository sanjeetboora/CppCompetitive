//https://leetcode.com/problems/maximum-length-of-pair-chain/

// LIS Method | Time: O(N^2) |  Space: O(N)

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int sz = pairs.size();
        sort(pairs.begin(), pairs.end());

        // for (vector<int>x : pairs) {
        //     cout << x[0] << " " << x[1] << ", ";
        // }
        // cout << endl;
        int arr[sz];
        arr[0] = 1;
        int maximum = 0;
        for (int i = 1; i < sz; i++) {
            arr[i] = 1;
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    arr[i] = max(arr[i], arr[j] + 1);
                }
            }
            maximum = max(arr[i], maximum);
            // cout << maximum << ", ";
        }
        // cout << endl;
        return maximum;
    }
};


// Time: O(NlogN) |  Space: O(1)
class Solution {
public:
    static bool compare(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int sz = pairs.size();
        sort(pairs.begin(), pairs.end(), compare);

        int curr = INT_MIN, maximum = 0;
        for (vector<int>x : pairs) {
            if (x[0] > curr) {
                curr = x[1];
                maximum++;
            }
        }
        return maximum;
    }
};