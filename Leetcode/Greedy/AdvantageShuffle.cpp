class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        int len = A.size();
        vector<pair<int, int> > b;
        for (int i = 0; i < len; i++) {
            b.push_back(make_pair(B[i], i));
        }
        sort(b.begin(), b.end());

        vector<int> xA(len, -1);
        vector<int>yB;
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] > b[j].first) {
                xA[b[j].second] = A[i];
                j++;
            }
            else {
                yB.push_back(A[i]);
            }
        }
        j = 0;
        for (int i = 0; i < len; i++) {
            if (xA[i] == -1) {
                xA[i] = yB[j];
                j++;
            }
        }
        return xA;

    }
};