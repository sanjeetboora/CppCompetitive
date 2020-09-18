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