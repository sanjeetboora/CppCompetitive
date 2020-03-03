#include<bits/stdc++.h>
#include<vector>
using namespace std;
class UnionOfIntervals {
public:
    int nthElement(vector <int> lowerBound, vector <int> upperBound, int n) {
        int len = lowerBound.size();
        int i = 0;
        long long min = 2000000000, max = -2000000000;
        for ( i = 0; i < len; ++i)
        {
            if (lowerBound[i] < min) {
                min = lowerBound[i];
            }
            if (upperBound[i] > max) {
                max = upperBound[i];
            }
        }
        while (min <= max) {
            long long mid = min + (max - min) / 2, count = 0;
            for ( i = 0; i < len; ++i)
            {
                if (mid >= lowerBound[i]) {
                    if (mid <= upperBound[i]) {
                        count += mid - lowerBound[i] + 1;
                    }
                    else {
                        count += upperBound[i] - lowerBound[i] + 1;
                    }
                }
            }
            if (count > n) {
                max = mid - 1;
            }
            else {
                min = mid + 1;
            }
        }
        return min;

    }
};

int main(int argc, char const *argv[])
{
    UnionOfIntervals u;
    int arr[1] = { -1500000000 };
    int arr1[1] = { 1500000000};
    vector<int> lBound(arr, arr + 1);
    vector<int> uBound(arr1, arr1 + 1);
    int ans = u.nthElement(lBound, uBound, 1500000091);
    cout << ans << endl;
    return 0;
}