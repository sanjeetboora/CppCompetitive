//https://leetcode.com/problems/top-k-frequent-words/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }

        struct cmp {
            bool operator()(const pair<string, int> &a, const pair<string, int> &b) {
                if (a.second == b.second) {
                    return a.first > b.first;
                }
                return a.second < b.second;
            };
        };

        priority_queue<pair<string, int>, vector<pair<string, int> >, cmp> pq(mp.begin(), mp.end());

        while (k--) {
            pair top = pq.top();
            res.push_back(top.first);
            pq.pop();
        }

        return res;

    }
};