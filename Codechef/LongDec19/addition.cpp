/* Problem -  */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
#define MODULO 1000000007

using namespace std;

long long compute(string str1, string str2) {
    long long res = 0;
    long long count = 0;
    bool beg = false;

    for (long long i = str1.length() - 1; i >= 0;) {
        if (str1[i] == str2[i] && str2[i] == '1') {
            beg = true;
            i--;
            count++;
            while (str1[i] != str2[i] && i >= 0) {
                i--;
                count++;
            }
            res = max(res, count);
            count = 0;
        }

        (beg == true) ? beg = false : i--;

    }

    return res;
}
long long setbits(string str, long long len) {
    long long count = 0;
    for (long long i = 0; i < len; i++) {
        if (str[i] == '1') {
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        while (str1.length() != str2.length()) {
            if (str1.length() > str2.length()) {
                str2 = '0' + str2;
            } else {
                str1 = '0' + str1;
            }
        }
        str1 = '0' + str1;
        str2 = '0' + str2;

        long long res = compute(str1, str2);
        long long count = 0;
        long long cset = setbits(str2, str2.length());

        if (cset) {
            cout << res + 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}