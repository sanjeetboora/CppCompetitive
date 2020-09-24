//https://www.geeksforgeeks.org/find-index-first-1-infinite-sorted-array-0s-1s/

int indexOfOne(int* arr, int l, int h) {

	while (l <= h) {
		int mid = l + (h - l) / 2;
		if (arr[mid] == 1 and (mid == 0 or arr[mid - 1] == 0)) {
			return mid;
		}

		if (arr[mid] == 1) {
			mid = h - 1;
		}
		else {
			mid = l + 1;
		}
	}
	return -1;

}


int positionOfFirstOne(int* arr) {

	int l = 0, h = 1;

	while (arr[h] == 0) {
		l = h;
		h *= 2;
	}

	return indexOfOne(arr, l, h);
}