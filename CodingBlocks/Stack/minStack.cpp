#include <bits/stdc++.h>
using namespace std;

void minStack(int* arr, int n) {
	int minimum = INT_MAX;
	stack<int> st;
	for (int i = 0; i < n; ++i)
	{
		int num = arr[i];
		if (num > minimum) {
			st.push(num);
		}
		else {
			st.push(2 * num - minimum);
			minimum = min(minimum, num);
		}
	}

	while (!st.empty()) {
		int num = st.top();
		if (num > minimum) {
			cout << num << ", " << minimum << endl;
			st.pop();
		}
		else {
			cout << (minimum) << ", " << minimum << endl;
			minimum = 2 * minimum - num;
			st.pop();
		}
	}

}


int main(int argc, char const *argv[])
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int arr[12] = {2, 3, 4, 1, 5, 0, 4, -1, 2, 1, -9, 8};
	int n = 12;
	minStack(arr, n);

	return 0;
}













