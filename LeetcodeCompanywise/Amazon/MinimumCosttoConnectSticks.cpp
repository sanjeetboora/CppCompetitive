//https://leetcode.com/problems/minimum-cost-to-connect-sticks/
//https://leetcode.com/discuss/interview-question/344677
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int res = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int x : sticks) {
            pq.push(x);
        }

        while (pq.size() > 1) {
            int a, b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();

            res += (a + b);
            pq.push(a + b);
        }
        return res;
    }
};