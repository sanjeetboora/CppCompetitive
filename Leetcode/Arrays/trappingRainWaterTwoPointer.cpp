//https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
	int trap(vector<int>& height) {
		int area = 0;
		int left = 0, leftMax = 0, right = height.size() - 1, rightMax = 0;
		while (left < right) {
			if (height[left] < height[right]) {
				if (height[left] > leftMax) {
					leftMax = height[left];
				}
				else {
					area += (leftMax - height[left]);
				}
				left++;
			}
			else {
				if (height[right] > rightMax) {
					rightMax = height[right];
				}
				else {
					area += (rightMax - height[right]);
				}
				right--;
			}

		}

		return area;

	}
};