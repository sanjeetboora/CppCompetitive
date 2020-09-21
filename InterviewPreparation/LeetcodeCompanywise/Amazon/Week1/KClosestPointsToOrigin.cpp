/*  https://leetcode.com/problems/k-closest-points-to-origin/  */

/* using heap O(NlogK)*/
class Solution {
public:

    int dist(vector<int> x) {
        return x[0] * x[0] + x[1] * x[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, vector<int> > >pq;
        vector<vector<int> >res;
        int i = 0;
        while (i < points.size()) {

            if (pq.size() < K) {
                pq.push({dist(points[i]), points[i]});
            }
            else if (pq.top().first > dist(points[i])) {
                pq.pop();
                pq.push({dist(points[i]), points[i]});
            }
            i++;
        }
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};