/* Problem - https://leetcode.com/problems/trapping-rain-water/ */
/* By Sanjeet Boora */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() == 0) {
			return 0;
		}
		int total = 0;
		stack<int> st;
		int i = 0;
		while (i < height.size()) {
			while (!st.empty() and height[st.top()] < height[i]) {
				int t = st.top();
				st.pop();
				if (st.empty()) {
					break;
				}
				int dis = i - st.top() - 1;
				total += dis * (min(height[i], height[st.top()]) - height[t]);
			}
			st.push(i++);
		}
		return total;
	}
};

