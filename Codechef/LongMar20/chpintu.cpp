
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--) {
        int N, M, num;
        map<int, int> m;
        cin >> N >> M;
        int fruits[N];
        for (int i = 0; i < N; i++) {

            cin >> fruits[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> num;
            m[fruits[i]] = m[fruits[i]] + num;
        }
        int minimum = m.begin()->second;

        for (auto i = m.begin(); i != m.end(); i++) {
            if ((i->second) < minimum)
                minimum = i->second;
        }
        cout << minimum << endl;
    }
    return 0;
}