class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        int maxRooms = 0;
        int meetings = intervals.size();
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minStartTime;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minEndTime;

        for (int i = 0; i < meetings; i++) {
            minStartTime.push(make_pair(intervals[i][0], intervals[i][1]));
        }
        if (!minStartTime.empty()) {
            minEndTime.push(make_pair(minStartTime.top().second, minStartTime.top().first));
            minStartTime.pop();
            maxRooms++;
        }

        while (!minStartTime.empty()) {
            pair<int, int> curr = minEndTime.top();
            pair<int, int> meet = minStartTime.top();
            minStartTime.pop();

            //cout<<curr.first<<" curr "<<curr.second<<endl;
            //cout<<meet.first<<" meet "<<meet.second<<endl;
            if (meet.first < curr.first ) {
                minEndTime.push(make_pair(meet.second, meet.first));
                int s = minEndTime.size();
                maxRooms = max(maxRooms, s);
            } else {
                while (!minEndTime.empty() and minEndTime.top().first <= meet.first) {
                    minEndTime.pop();
                }
                minEndTime.push(make_pair(meet.second, meet.first));
            }
            // cout<<maxRooms<<endl;
        }
        return maxRooms;
    }
};