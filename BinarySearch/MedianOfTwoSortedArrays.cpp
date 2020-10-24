//https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0, high = len1;

        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (len1 + len2 + 1) / 2 - partition1;

            int maxLeft1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = partition1 == len1 ? INT_MAX : nums1[partition1];

            int maxLeft2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = partition2 == len2 ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 and maxLeft2 <= minRight1) {
                if ((len1 + len2) & 1) {
                    return max(maxLeft1, maxLeft2);
                }
                else {
                    double ans = (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                    return ans;
                }
            }

            else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            }
            else {
                low = partition1 + 1;
            }
        }
        return 1.0;
    }
};