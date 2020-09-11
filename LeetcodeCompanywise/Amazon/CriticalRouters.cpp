//https://leetcode.com/discuss/interview-question/436073/
#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, int par, unordered_map<int, list<int> > &adjList,
         unordered_map<int, pair<int, int> > &time, vector<int> &result, int &currTime) {

    time[curr] = {currTime, currTime};
    // cout << "current  ->> " << curr << "  -->> " << currTime << endl;
    currTime++;
    int child = 0;
    for (int nbr : adjList[curr]) {
        if (!time.count(nbr)) {
            child++;
            dfs(nbr, curr, adjList, time, result, currTime);
            time[curr].second = min(time[curr].second, time[nbr].second);

            if (par != -1 and time[nbr].second >= time[curr].first) {
                result.push_back(curr);
                // cout << curr << "-> curr.first " << time[curr].first << ", nbr " << time[nbr].second << endl;
            }
        }
        else if (nbr != par) {
            time[curr].second = min(time[curr].second, time[nbr].second);
        }
        if (par == -1 and child > 1) {
            result.push_back(curr);
        }
    }
    return;

}

vector<int> criticalConnections(int n, vector<vector<int> >& connections) {
    unordered_map<int, list<int> > adjList;
    unordered_map<int, pair<int, int> > time; //first -> discovery time, second -> lowest time
    for (int i = 0; i < connections.size(); i++) {
        adjList[connections[i][0]].push_back(connections[i][1]);
        adjList[connections[i][1]].push_back(connections[i][0]);
    }
    vector<int>result;
    int currTime = 1;
    dfs(connections[0][0], -1, adjList, time, result, currTime);

    return result;

}

int main() {
    int vertices = 7;
    int edges = 7;
    vector<vector<int> > connections = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 5}, {5, 6}, {3, 4}};
    vector<int> articulationPoints = criticalConnections(edges, connections);
    for (int x : articulationPoints) {
        cout << x << ", ";
    }
    cout << endl;
}







