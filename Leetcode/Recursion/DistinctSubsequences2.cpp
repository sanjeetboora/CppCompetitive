class Solution {
public:

    int subseq(string s, string t, int i, int j, int sSize, int tSize) {
        if (i == sSize or j == tSize or sSize - i < tSize - j) {
            return j == tSize ? 1 : 0;
        }

        int ans = subseq(s, t, i + 1, j, sSize, tSize);

        if (s[i] == t[j]) {
            ans  +=  subseq(s, t, i + 1, j + 1, sSize, tSize);
        }

        return ans;
    }


    int numDistinct(string s, string t) {
        return subseq(s, t, 0, 0, s.length(), t.length());
    }
};


