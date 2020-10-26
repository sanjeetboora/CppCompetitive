/* Problem - https://leetcode.com/problems/search-a-2d-matrix/ */
/* By Sanjeet Boora */

class Solution {
public:
	bool binarySearchCol(vector<vector<int>>& matrix, int row, int target) {
		int c = matrix[row].size();
		int low = 0, high = c - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (target == matrix[row][mid]) {
				return true;
			}
			else if (target < matrix[row][mid]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		return false;
	}
	int binarySearch(vector<vector<int>>& matrix, int target) {
		int r = matrix.size();
		int c = matrix[0].size();
		int low = 0, high = r - 1;

		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (target >= matrix[mid][0] and target <= matrix[mid][c - 1]) {
				return mid;
			}
			else if (target < matrix[mid][0]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		return -1;
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int r = matrix.size();
		int c = 0;
		if (r > 0) {
			c = matrix[0].size();
		}
		if (r == 0 or c == 0) {
			return false;
		}
		int possibleRow = binarySearch(matrix, target);
		if (possibleRow == -1) {
			return false;
		}

		bool found = binarySearchCol(matrix, possibleRow, target);
		return found;
	}
};