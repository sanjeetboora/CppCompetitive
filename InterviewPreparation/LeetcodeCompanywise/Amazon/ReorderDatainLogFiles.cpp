//https://leetcode.com/problems/reorder-data-in-log-files/
class Solution {
public:

    static bool cmp(string a, string b) {
        int pos1 = a.find(' ', 0) + 1;
        int pos2 = b.find(' ', 0) + 1;
        if (a.substr(pos1) == b.substr(pos2)) {
            return a < b;
        }
        return a.substr(pos1) < b.substr(pos2);
    }
    vector<string> reorderLogFiles(vector<string>& logs) {

        int s = logs.size();
        vector<string> letter;
        vector<string> digit;
        for (int i = 0; i < s; i++) {
            int pos = logs[i].find(' ', 0);
            if (isalpha(logs[i][pos + 1])) {
                letter.push_back(logs[i]);
            }
            else {
                digit.push_back(logs[i]);
            }
        }

        sort(letter.begin(), letter.end(), cmp);

        letter.insert( letter.end(), digit.begin(), digit.end() );

        return letter;
    }
};