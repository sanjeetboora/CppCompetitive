/* Problem - https://leetcode.com/problems/valid-parentheses/ */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        if (s.length() == 0) {
            return true;
        }

        for (char ch : s) {
            if (ch == '(' or ch == '{' or ch == '[') {
                st.push(ch);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                if (ch == ')' and st.top() == '(') {
                    st.pop();
                }
                else if (ch == '}' and st.top() == '{') {
                    st.pop();
                }
                else if (ch == ']' and st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty() ? true : false;
    }
};


