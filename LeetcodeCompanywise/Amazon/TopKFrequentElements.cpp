class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        struct cmp {
            bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
                return a.second < b.second;
            };
        };
        unordered_map<int, int>mp;
        for (int x : nums) {
            mp[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq(mp.begin(), mp.end());

        while (k--) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;

    }
};