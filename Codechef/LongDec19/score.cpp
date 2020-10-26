/* Problem -  */
/* By Sanjeet Boora */
#include <bits/stdc++.h>
using namespace std;

long long int totalScore(int N) {
    unordered_map<int, int> m;
    while (N--) {
        int a, b;
        cin >> a >> b;

        if (a < 9) {
            if (m.count(a)) {
                if (m[a] < b) {
                    m[a] = b;
                }
            }
            else {
                m[a] = b;
            }
        }
    }
    long long int score = 0;
    for (auto it : m) {
        score += it.second;
    }
    return score;

}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cout << totalScore(N) << endl;
    }

}
