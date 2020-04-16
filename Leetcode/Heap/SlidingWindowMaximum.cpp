class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // priority_queue< pair<int, int>, vector< pair<int, int>>,greater<int> > minHeap;
        deque< pair<int, int> > q;
        vector<int> res;
        int i = 0;
        q.push_back(make_pair(nums[i], i++));
        while (i < k) {

            while (!q.empty() and nums[i] > q.front().first) {
                q.pop_front();
            }

            while (!q.empty() and q.back().first < nums[i] ) {
                q.pop_back();
            }

            q.push_back(make_pair(nums[i], i++));
        }

        res.push_back(q.front().first);
        while (i < nums.size()) {

            while (!q.empty() and q.front().second <= i - k) {
                q.pop_front();
            }
            while (!q.empty() and q.back().first < nums[i] ) {
                q.pop_back();
            }
            q.push_back(make_pair(nums[i], i++));
            res.push_back(q.front().first);
        }
        
        return res;
    }
};