/* Problem -  */
/* By Sanjeet Boora */
#include <bits/stdc++.h>
using namespace std;

int maxSubLen(int N, string str) {
  unordered_map<char, int> m;
  char con = 'a';
  for (int i = 0; i < 26; i++) {
    int len = INT_MAX;
    int temp = -1;
    for (int j = 0; j < N; j++) {
      if (str[j] == con) {
        if (temp != -1) {
          len = min(len, j - temp);
        }
        temp = j;
      }
    }
    if (len < INT_MAX) {
      //cout<<len<<endl;
      m[con] = len;
    }
    con++;
  }

  int minlen = INT_MAX;
  for (auto it : m) {
    minlen = min(minlen, it.second);
    //cout<<it.second<<endl;
  }
  if (minlen < N) {
    return N - minlen;
  }
  return 0;

}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    string str;
    cin >> str;
    cout << maxSubLen(N, str) << endl;
  }

}
