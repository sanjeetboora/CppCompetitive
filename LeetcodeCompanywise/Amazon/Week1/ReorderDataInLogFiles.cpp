class Solution {
public:

    bool static cmp(string a, string b) {
        int posA = a.find(" ", 0);
        int posB = b.find(" ", 0);
        if (a.substr(posA + 1) != b.substr(posB + 1)) {
            return a.substr(posA + 1) < b.substr(posB + 1);
        }
        return a < b;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter;
        vector<string> digit;
        if (!logs.size()) return letter;

        for (int i = 0; i < logs.size(); i++) {
            string str = logs[i];
            int pos = str.find(" ", 0);

            if (isalpha(str[pos + 1])) {
                letter.push_back(str);
            }
            else {
                digit.push_back(str);
            }

        }
        sort(letter.begin(), letter.end(), cmp);
        letter.insert(letter.end(), digit.begin(), digit.end());
        return letter;
    }
};