class Solution {
public:
    int arr[1000000] = {0};
    int numDecodings(string s) {
        if (s.length() == 0) {
            return 1;
        }
        if (arr[s.length()]) {
            return arr[s.length()];
        }
        int ans = 0;
        if (s[0] - '0' == 0) {
            return 0;
        }
        if (s[0] - '0' > 0) {
            ans += numDecodings(s.substr(1));
        }
        if (s.length() >= 2 and stoi(s.substr(0, 2)) <= 26 and stoi(s.substr(0, 2)) > 0) {
            ans += numDecodings(s.substr(2));
        }
        arr[s.length()] = ans;
        return ans;
    }
};