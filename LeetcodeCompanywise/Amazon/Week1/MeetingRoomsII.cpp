//https://leetcode.com/problems/meeting-rooms-ii/

/*  Using 2 min Heaps |   Time: O(NlogN) | Space: O(2N)   */

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int maxRooms = 0;
        int sz = intervals.size();
        if (!sz) return maxRooms;

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >minStart;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >minEnd;

        for (int i = 0; i < sz; i++) {
            minStart.push({intervals[i][0], intervals[i][1]});
        }

        pair<int, int> t = minStart.top();
        minStart.pop();
        minEnd.push({t.second, t.first});
        maxRooms++;
        while (!minStart.empty()) {
            t = minStart.top();
            minStart.pop();
            pair<int, int> curr = minEnd.top();
            if (t.first >= curr.first) {
                minEnd.pop();
            }
            minEnd.push({t.second, t.first});
            maxRooms = max(maxRooms, (int)minEnd.size());
        }
        return maxRooms;
    }
};




/*  Using 1 min Heap and sorting actual array  |  Time: O(NlogN) | Space: O(N) */

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int maxRooms = 0;
        int sz = intervals.size();
        if (sz == 0) return maxRooms;

        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int> >minEnd;

        minEnd.push(intervals[0][1]);
        maxRooms++;

        for (int i = 1; i < sz; i++) {
            int endTime = minEnd.top();
            if (endTime <= intervals[i][0]) {
                minEnd.pop();
            }
            minEnd.push(intervals[i][1]);
            maxRooms = max(maxRooms, (int) minEnd.size());
        }

        return maxRooms;
    }
};




/************************************************************/


class Solution {
public:
    unordered_map<int, vector<string> >mp;
    unordered_set<string> wordset;
    int maxlen = 0;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string x : wordDict) {
            wordset.insert(x);
            maxlen = max(maxlen, (int)x.length());
        }

        vector<string> res = helper(s, 0);
        return res;
    }

    vector<string> helper(string s, int st) {
        if (mp.count(st) != 0) return mp[st];

        vector<string> tmp;
        for (int i = st; i < s.length() and i <= st + maxlen; i++) {
            string x = s.substr(st, i - st + 1);
            if (wordset.find(x) != wordset.end()) {
                if (st + x.length() == s.length()) {
                    tmp.push_back(x);
                }
                else {
                    vector<string> subtmp = helper(s, i + 1);
                    for (string y : subtmp) {
                        tmp.push_back(x + " " + y);
                    }
                }
            }
        }
        mp[st] = tmp;
        return tmp;
    }

};

