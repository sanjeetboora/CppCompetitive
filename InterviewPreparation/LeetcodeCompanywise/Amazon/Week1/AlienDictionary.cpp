/*  https://leetcode.com/problems/alien-dictionary/   */

/*  BFS Topological Sort  */
class Solution {
public:
    unordered_map<char, list<char> >mp;
    unordered_map<char, int>freq;

    string alienOrder(vector<string>& words) {
        int sz = words.size();
        string res = "";
        for (int i = 0; i < sz; i++) {
            for (char ch : words[i]) {
                freq[ch] = 0;
                mp[ch] = {};
            }
        }

        for (int i = 0; i < sz - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            if (s1.length() > s2.length() and mismatch(s2.begin(), s2.end(), s1.begin()).first == s2.end()) {
                return "";
            }

            for (int j = 0; j < min(s1.length(), s2.length()); j++) {
                if (s1[j] != s2[j]) {
                    mp[s1[j]].push_back(s2[j]);
                    freq[s2[j]]++;
                    break;
                }
            }
        }

        queue<char> q;
        for (auto x : freq) {
            if (x.second == 0) {
                q.push(x.first);
            }
        }

        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            res += ch;
            for (auto x : mp[ch]) {
                freq[x]--;
                if (freq[x] == 0) {
                    q.push(x);
                }
            }
        }

        if (res.length() < freq.size()) {
            return "";
        }

        return res;

    }
};



/*   DFS Topological Sort   */

class Solution {
public:
    unordered_map<char, unordered_set<char> >g;

    bool dfs(unordered_set<char> &visited, unordered_set<char> &inStack, string& op, char ch) {
        if (inStack.count(ch)) return true;
        if (visited.count(ch)) return false;

        inStack.insert(ch);
        visited.insert(ch);
        for (auto x : g[ch]) {
            bool cycle = dfs(visited, inStack, op, x);
            if (cycle) return true;
        }
        op += ch;
        inStack.erase(ch);
        return false;
    }

    string topo() {
        unordered_set<char> visited;
        unordered_set<char> inStack;
        string op = "";
        for (auto x : g) {
            bool cycle = dfs(visited, inStack, op, x.first);
            if (cycle) {
                return "";
            }
        }
        if (op.length() < g.size()) {
            return "";
        }
        reverse(op.begin(), op.end());

        return op;

    }


    string alienOrder(vector<string>& words) {
        int sz = words.size();
        if (sz == 1) {
            return words.front();
        }

        for (int i = 1; i < sz; i++) {
            string s1 = words[i - 1];
            string s2 = words[i];
            bool found = false;
            for (int j = 0; j < max(s1.length(), s2.length()); j++) {
                if (j < s1.length() and g.count(s1[j]) == 0) {
                    g[s1[j]] = unordered_set<char>();
                }
                if (j < s2.length() and g.count(s2[j]) == 0) {
                    g[s2[j]] = unordered_set<char>();
                }
                if (j < s1.length() and j < s2.length() and s1[j] != s2[j] and !found) {
                    g[s1[j]].insert(s2[j]);
                    found = true;
                }

                if (s1.length() > s2.length() and j == s2.length() - 1 and !found) {
                    return "";
                }

            }
        }

        string res = topo();
        return res;
    }
};


/*  BFS Better  */
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 0) return "";
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;

        // initialize
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                indegree[c] = 0;
            }
        }

        // build graph and record indegree
        for (int i = 0; i < words.size() - 1; i++) {
            string cur = words[i];
            string nex = words[i + 1];
            if (cur.length() > nex.length() and mismatch(nex.begin(), nex.end(), cur.begin()).first == nex.end()) {
                return "";
            }
            int len = min(cur.size(), nex.size());
            for (int j = 0; j < len; j++) {
                if (cur[j] != nex[j]) {
                    unordered_set<char> set = graph[cur[j]];
                    if (set.find(nex[j]) == set.end()) {
                        graph[cur[j]].insert(nex[j]); // build graph
                        indegree[nex[j]]++; // add indegree
                    }
                    break;
                }
            }
        }

        // topoligical sort
        string ans;
        queue<char> q;
        for (auto& e : indegree) {
            if (e.second == 0) {
                q.push(e.first);
            }
        }
        while (!q.empty()) {
            char cur = q.front();
            q.pop();
            ans += cur;

            if (graph[cur].size() != 0) {
                for (auto& e : graph[cur]) {
                    indegree[e]--;
                    if (indegree[e] == 0) {
                        q.push(e);
                    }
                }
            }
        }

        // tell if it is cyclic
        return ans.length() == indegree.size() ? ans : "";
    }
};
