// https://www.geeksforgeeks.org/find-winner-nim-game/

string winner(int n, int* arr) {

	int res = 0;
	for (int i = 0; i < n; i++) {
		res ^= arr[i];
	}
	if (res == 0 or n & 1 == 0) {
		return "Alice";
	}
	else {
		return "Bob";
	}
}