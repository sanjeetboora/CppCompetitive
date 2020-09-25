//https://www.geeksforgeeks.org/count-of-days-remaining-for-the-next-day-with-higher-temperature/

vector<int> waitingDays(int* nums, int n) {

	vector<int> res(n);
	if (n == 0) return res;

	stack<int> st;

	for (int i = 0; i < n; ++i) {
		while (!st.empty() and nums[st.top()] < nums[i]) {
			int t = st.top();
			res[t] = i - t;
			st.pop();
		}
		st.push(i);
	}
	return res;
}