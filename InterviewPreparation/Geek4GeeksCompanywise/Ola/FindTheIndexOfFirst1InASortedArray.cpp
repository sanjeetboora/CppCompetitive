//https://www.geeksforgeeks.org/find-index-first-1-sorted-array-0s-1s/

int startIndex(int* arr, int n) {

	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == 1 and (mid == 0 or arr[mid - 1] == 0)) {
			return mid;
		}
		if (arr[mid] == 1) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}