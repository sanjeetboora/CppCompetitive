/* https://leetcode.com/problems/longest-palindromic-substring/ */

/* Dynamic Programming  O(N^2)*/
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int sz = s.length();
        if (!sz) return res;

        int **arr = new int*[sz];

        for (int i = 0; i < sz; i++) {
            arr[i] = new int[sz];
        }

        pair<int, int> p = {0, 0};

        for (int ws = 0; ws <= 1; ws++) {
            for (int i = 0; i < sz; i++) {
                for (int j = i; j <= i + ws and j < sz; j++) {
                    if (s[i] == s[j]) {
                        arr[i][j] = 1;

                        if (j - i > p.second - p.first) {
                            p = {i, j};
                        }
                    }
                    else {
                        arr[i][j] = 0;
                    }
                }
            }
        }

        for (int ws = 2; ws < sz; ws++) {
            for (int i = 0; i < sz - 2; i++) {
                for (int j = i + ws; j < sz; j++) {
                    if (s[i] == s[j] and arr[i + 1][j - 1] == 1) {
                        arr[i][j] = 1;

                        if (j - i > p.second - p.first) {
                            p = {i, j};
                        }
                    }
                    else {
                        arr[i][j] = 0;
                    }
                }
            }
        }
        res = s.substr(p.first, p.second - p.first + 1);
        return res;
    }
};

/* Expand Around Center  O(N^2)*/
class Solution {
public:
    pair<int, int> expandAround(string str, int l, int r) {
        pair<int, int>p;
        while (l >= 0 and r < str.length() and str[l] == str[r]) {
            p = {l, r};
            l--;
            r++;
        }
        return p;
    }
    string longestPalindrome(string s) {
        string res = "";
        int sz = s.length();
        if (!sz) return res;
        int l = 0, maxlen = 0;
        for (int i = 0; i < sz; i++) {
            pair<int, int>p1 = expandAround(s, i, i);
            pair<int, int>p2 = expandAround(s, i, i + 1);

            if ((p1.second - p1.first + 1 ) > maxlen) {
                l = p1.first;
                maxlen = p1.second - p1.first + 1;
            }

            if ((p2.second - p2.first + 1 ) > maxlen) {
                l = p2.first;
                maxlen = p2.second - p2.first + 1;
            }
        }
        res = s.substr(l, maxlen);
        return res;
    }
};



/*Manacher's Algo  O(N)*/

class Solution {
public:
    string addBoundaries(string str) {
        string modified = "@#";
        for (char s : str) {
            modified += s;
            modified += "#";
        }
        modified += "$";
        return modified;
    }

    string longestPalindrome(string s) {
        string res = "";

        int sz = s.length();
        if (sz == 0) return res;

        string modified = addBoundaries(s);
        int* arr = new int[modified.length()];
        for (int i = 0; i < modified.length(); i++) arr[i] = 0;

        int c = 1, r = 1, maxlen = 0, maxidx = 0;
        for (int i = 1; i < modified.length() - 1; i++) {
            int mirr = 2 * c - i;
            if (i < r) {
                arr[i] = min(arr[mirr], r - i);
            }

            while (modified[i + (1 + arr[i])] == modified[i - (1 + arr[i])]) {
                arr[i]++;
            }

            if (i + arr[i] > r) {
                r = i + arr[i];
                c = i;
                if (maxlen < arr[i]) {
                    maxlen = arr[i];
                    maxidx = i;
                }
            }
        }

        for (int i = maxidx - maxlen; i <= maxidx + maxlen; i++) {
            if (modified[i] != '#') {
                res += modified[i];
            }
        }

        return res;


    }
};











