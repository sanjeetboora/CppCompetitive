//https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

		int lenA = nums1.size();
		int lenB = nums2.size();

		int mid = (lenA + lenB + 1) / 2;

		int aMinCount = 0;
		int aMaxCount = lenA;

		while (aMinCount <= aMaxCount) {

			int aCount = aMinCount + ((aMaxCount - aMinCount) / 2);
			int bCount = mid - aCount;
			int maxLeftA = aCount == 0 ? -2147483648 : nums1[aCount - 1] ;
			int maxLeftB = bCount == 0 ? -2147483648 : nums2[bCount - 1] ;
			int minRightA = aCount == lenA ? 2147483647 : nums1[aCount] ;
			int minRightB = bCount == lenB ? 2147483647 : nums2[bCount] ;

			if ( maxLeftA <= minRightB && maxLeftB <= minRightA) {
				if ((lenA + lenB) & 1) {
					return max(maxLeftA, maxLeftB);
				}
				else {
					return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
				}
			}
			else if (maxLeftA > minRightB) {
				aMaxCount = aCount - 1;
			}
			else {
				aMinCount = aCount + 1;
			}
		}
		return -1;
	}
};