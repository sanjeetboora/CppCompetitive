/* https://leetcode.com/problems/longest-palindromic-substring/ */


/*Manacher's Algo  O(N)*/

class Solution {
public:
    string addBoundaries(string str) {
        string res = "@#";

        for (char s : str) {
            res += s;
            res += "#";
        }
        res += "$";
        return res;
    }
    string palString(string modified, int maxidx, int val) {
        string res = modified.substr(maxidx - val, (val * 2) + 1);
        for (int i = 0; i < res.length(); i++) {
            if (res[i] != '#') {
                result += res[i];
            }
        }
        return result;


    }
    string longestPalindrome(string s) {
        string res = "";
        if (s.length() == 0) return res;
        string modified = addBoundaries(s);
        int* arr = new int[modified.length()];
        for (int i = 0; i < modified.length(); i++) arr[i] = 0;
        int c = 1, r = 1;
        for (int i = 1; i < modified.length() - 1; i++) {
            int mirr  = 2 * c - i;

            if (i < r) {
                arr[i] = min(arr[mirr], r - i);
            }

            while (modified[i + (1 + arr[i])] == modified[i - (1 + arr[i])]) {
                arr[i]++;

            }

            if (i + arr[i] > r) {
                r = i + arr[i];
                c = i;
            }
        }
        cout << endl;

        int maxidx = max_element(arr, arr + modified.length()) -  arr;

        res = palString(modified, maxidx, arr[maxidx]);

        return res;

    }
};