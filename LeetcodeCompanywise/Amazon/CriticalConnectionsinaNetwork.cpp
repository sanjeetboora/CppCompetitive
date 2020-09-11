//https://leetcode.com/problems/critical-connections-in-a-network/
//https://leetcode.com/discuss/interview-question/372581
class Solution {
public:

    void dfs(int curr, int par, unordered_map<int, list<int> > &adjList,
             unordered_map<int, pair<int, int> > &time, vector<vector<int> > &result, int &currTime) {

        time[curr] = {currTime, currTime};
        currTime++;

        for (int nbr : adjList[curr]) {
            if (!time.count(nbr)) {
                dfs(nbr, curr, adjList, time, result, currTime);
                time[curr].second = min(time[curr].second, time[nbr].second);

                if (time[nbr].second > time[curr].first) {
                    result.push_back({nbr, curr});
                }
            }
            else if (nbr != par) {
                time[curr].second = min(time[curr].second, time[nbr].second);
            }
        }
        return;

    }

    vector<vector<int> > criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int> > adjList;
        unordered_map<int, pair<int, int> > time; //first -> discovery time, second -> lowest time
        for (int i = 0; i < connections.size(); i++) {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int> >result;
        int currTime = 1;
        dfs(connections[0][0], 0, adjList, time, result, currTime);

        for (auto p : result) {
            cout << p[0] << ", " << p[1] << endl;
        }
        return result;

    }
};