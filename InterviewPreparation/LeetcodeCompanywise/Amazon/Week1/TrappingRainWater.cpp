/*   https://leetcode.com/problems/trapping-rain-water/submissions/    */

/*   Dynamic Programming    */
class Solution {
public:
    int trap(vector<int>& height) {
        int s = height.size();
        if (!s) return 0;

        vector<int> leftGreater;
        leftGreater.push_back(height[0]);
        int area = 0;
        for (int i = 1; i < s; i++) {
            leftGreater.push_back(max(height[i], leftGreater[i - 1]));
        }

        int rightGreater = 0;
        for (int i = s - 1; i >= 0; i--) {
            int rightGreater = max(rightGreater, height[i]);
            area += min(leftGreater[i], rightGreater) - height[i];
        }
        return area;
    }
};

/*   Two Pointer   */

class Solution {
public:
    int trap(vector<int>& height) {
        int s = height.size();
        if (!s) return 0;

        int area = 0;

        int left = 0, right = s - 1, leftMax = 0, rightMax = 0;

        while (left <= right) {
            if (leftMax <= rightMax) {

                if (height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {
                    area += (leftMax - height[left]);
                }
                left++;
            }

            else {
                if (height[right] >= rightMax) {
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