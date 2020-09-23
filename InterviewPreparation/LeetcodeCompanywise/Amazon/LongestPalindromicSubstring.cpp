//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string modify(string s) {
        string m = "$#";

        for (int i = 0; i < s.length(); i++) {
            m += s[i];
            m += "#";
        }
        m += "@";
        return m;
    }

    string longestPalindrome(string s) {
        int sz = s.length();
        if (!sz) return "";

        string m = modify(s);
        int count[m.length()];
        for (int i = 1; i < m.length(); i++) count[i] = 0;

        int c = 1, r = 1, maxlen = 0, maxidx = 0;
        for (int i = 1; i < m.length() - 1; i++) {
            int mirr = 2 * c - i;
            if (r > i) {
                count[i] = min(count[mirr], r - i);
            }

            while (m[i + (1 + count[i])] == m[i - (1 + count[i])]) {
                count[i]++;
            }

            if (i + count[i] > r) {
                c = i;
                r = i + count[i];
                if (maxlen < count[i]) {
                    maxlen =  count[i];
                    maxidx = i;
                }
            }

        }
        string res = "";
        for (int i = maxidx - maxlen; i <= maxidx + maxlen; i++) {
            if (m[i] != '#') {
                res += m[i];
            }
        }
        return res;
    }
};