class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        int maxRooms = 0;
        vector<int> st;
        vector<int> ed;

        for (int i = 0; i < intervals.size(); i++) {
            st.push_back(intervals[i][0]);
            ed.push_back(intervals[i][1]);
        }
        sort(st.begin(), st.end());
        sort(ed.begin(), ed.end());
        int s = 0, e = 0;

        while (s < intervals.size()) {

            if (st[s] >= ed[e]) {
                maxRooms--;
                e++;
            }

            maxRooms++;
            s++;
        }
        return maxRooms;

    }
};