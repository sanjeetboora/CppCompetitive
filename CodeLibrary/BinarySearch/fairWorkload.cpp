#include<bits/stdc++.h>
#include<vector>
using namespace std;
class FairWorkload {
public:
    int getMostWork(vector <int> folders, int workers) {
        int n = folders.size();
        int low = *max_element(folders.begin(), folders.end());
        int high = accumulate(folders.begin(), folders.end(), 0);
        while (low < high) {
            int mid = low + (high - low) / 2;
            int w = 1, load = 0;
            for (int i = 0; i < n; i++) {
                if (folders[i] + load <= mid) {
                    load += folders[i];
                }
                else {
                    load = folders[i];
                    w++;
                }
            }
            if (w <= workers) {
                high = mid;
            }
            else {

                low = mid + 1;
            }
        }
        return low;
    }
};

int main(int argc, char const *argv[])
{   int arr[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    vector<int> folders (arr, arr + 9);
    int workers = 3;
    FairWorkload f;

    cout << f.getMostWork(folders, workers) << endl;
    return 0;
}