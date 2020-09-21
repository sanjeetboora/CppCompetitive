//https://leetcode.com/problems/top-k-frequent-words/

class Compare {
public:
    bool operator()(pair<int, string>x, pair<int, string> y) {
        if (x.first == y.first) {
            return x.second > y.second;
        }
        return x.first < y.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int sz = words.size();
        vector<string> res;
        priority_queue<pair<int, string>, vector<pair<int, string> >, Compare > pq;

        if (!sz) return res;

        map<string, int> mp;
        for (string w : words) {
            mp[w]++;
        }

        for (auto x : mp) {
            pq.push({x.second, x.first});
        }
        int i = 0;
        while (i < k) {
            res.push_back(pq.top().second);
            pq.pop();
            i++;
        }

        return res;
    }
};