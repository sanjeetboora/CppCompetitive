//https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
	int trap(vector<int>& height) {
		vector<int> maxLeft;
		if (height.size() == 0) {
			return 0;
		}

		maxLeft.push_back(height[0]);
		for (int i = 1; i < height.size(); i++) {
			maxLeft.push_back( max(maxLeft[i - 1], height[i]) );
		}

		int area = 0;
		int maxRight = height[height.size() - 1];
		for (int i = height.size() - 1; i > 0; i--) {
			maxRight = max(maxRight, height[i]);
			area += (min(maxLeft[i], maxRight) - height[i]);
		}
		return area;

	}
};