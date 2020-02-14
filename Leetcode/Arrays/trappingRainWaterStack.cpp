//https://leetcode.com/problems/trapping-rain-water


class Solution {
public:
	int trap(vector<int>& height) {
		int area = 0;

		stack<int> st;

		for (int i = 0; i < height.size(); i++) {

			while (!st.empty() && height[i] > height[st.top()] ) {
				int t = st.top();
				st.pop();
				if (st.empty()) {
					break;
				}
				area += (i - st.top() - 1) * (min(height[st.top()], height[i]) - height[t]);
			}

			st.push(i);
		}

		return area;

	}
};