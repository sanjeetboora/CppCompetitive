#include <iostream>
using namespace std;

int ways(int n, int* dp) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int step1 = ways(n - 1, dp);
    int step2 = ways(n - 2, dp);
    int step3 = ways(n - 3, dp);
    dp[n] = step1 + step2 + step3;

    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int dp[1000] = {0};
        cout << ways(n, dp) << endl;
    }
    return 0;
}