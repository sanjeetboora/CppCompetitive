class Solution {
public:
    void subseq(string str, string seq, string t, int& num) {
        if (str == "") {
            if (seq == t) {
                num = num + 1;
            }
            return;
        }

        char ch = str[0];
        subseq(str.substr(1), seq + ch, t, num);
        subseq(str.substr(1), seq, t, num);

    }

    int numDistinct(string s, string t) {
        int num = 0;
        subseq( s, "", t, num);
        return num;
    }
};