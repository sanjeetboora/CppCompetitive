// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[], int width[], int length[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;


        int A[1000], B[1000], C[10001];
        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            A[i] = a;
            B[i] = b;
            C[i] = c;
        }
        cout << maxHeight(A, B, C, n) << endl;
    }

} // } Driver Code Ends

void allRotations(int* height, int* width, int* length, int n, pair<pair<int, int>, int>* allBoxes) {
    int idx = 0;
    for (int i = 0; i < n; i++) {
        pair<pair<int, int>, int> x = {{max(height[i], width[i]), min(height[i], width[i])}, length[i]};
        pair<pair<int, int>, int> y = {{max(width[i], length[i]), min(width[i], length[i])}, height[i]};
        pair<pair<int, int>, int> z = {{max(length[i], height[i]), min(length[i], height[i])}, width[i]};
        allBoxes[idx++] = x;
        allBoxes[idx++] = y;
        allBoxes[idx++] = z;
    }
}

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {

    if (a.first.first * a.first.second == b.first.first * b.first.second) {
        return a.second < b.second;
    }
    return a.first.first * a.first.second > b.first.first * b.first.second;
}

/*The function takes an array of heights, width and
length as its 3 arguments where each index i value
determines the height, width, length of the ith box.
Here n is the total no of boxes.*/
int maxHeight(int height[], int width[], int length[], int n)
{
    int m = 3 * n;
    pair<pair<int, int>, int> allBoxes[m];

    allRotations(height, width, length, n, allBoxes);
    sort(allBoxes, allBoxes + m, compare);

    int dp[m] = {0};
    int sol[m] = {0};
    dp[0] = allBoxes[0].second;
    sol[0] = 0;
    int maxHeight = dp[0];
    for (int i = 1; i < m; i++) {
        dp[i] = allBoxes[i].second;
        sol[i] = i;
        for (int j = 0; j < i; j++) {
            if (allBoxes[i].first.first < allBoxes[j].first.first and
                    allBoxes[i].first.second < allBoxes[j].first.second and
                    dp[j] + allBoxes[i].second > dp[i]) {
                dp[i] = dp[j] + allBoxes[i].second;
                sol[i] = j;
            }
        }
        maxHeight = max(maxHeight, dp[i]);
    }
    return maxHeight;
}












