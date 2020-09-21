//https://leetcode.com/discuss/interview-question/373202
#include <bits/stdc++.h>
using namespace std;
static bool cmp(vector<int>a, vector<int>b) {
	return a[1] < b[1];
}

vector<vector<int> > closestTarget(vector<vector<int> > a, vector<vector<int> > b, int target) {
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	vector<vector<int> > res;
	int maxTarget = INT_MIN;
	int i = 0, j = b.size() - 1;
	while (i < a.size() and j >= 0) {
		int one = a[i][1];
		int two = b[j][1];
		if ((one + two) > target) {
			j--;
		}
		else if ((one + two) < target and (one + two) >= maxTarget) {
			if (one + two > maxTarget) {
				maxTarget =  one + two;
				res.clear();
			}

			res.push_back({a[i][0], b[j][0]});
			i++;
		}
		else {
			if (one + two > maxTarget) {
				maxTarget =  one + two;
				res.clear();
			}
			res.push_back({a[i][0], b[j][0]});
			i++;
			j--;
		}
	}
	return res;

}

int main(int argc, char const *argv[])
{
	vector<vector<int> >a = {{1, 8}, {2, 15}, {3, 9}};
	vector<vector<int> >b = {{1, 8}, {2, 11}, {3, 12}};
	int target = 20;

	vector<vector<int> >res = closestTarget(a, b, target);
	for (vector<int>x : res)
	{
		cout << x[0] << ", " << x[1] << endl;
	}

	return 0;
}


// Input:
// a = [[1, 2], [2, 4], [3, 6]]
// b = [[1, 2]]
// target = 7

// Output: [[2, 1]]

// Explanation:
// There are only three combinations [1, 1], [2, 1], and [3, 1], which have a total sum of 4, 6 and 8, respectively.
// Since 6 is the largest sum that does not exceed 7, [2, 1] is the optimal pair.

//a = {{1, 2}, {2, 4}, {3, 6}}
// b = {{1, 2}}


// Input:
// a = [[1, 3], [2, 5], [3, 7], [4, 10]]
// b = [[1, 2], [2, 3], [3, 4], [4, 5]]
// target = 10

// Output: [[2, 4], [3, 2]]

// Explanation:
// There are two pairs possible. Element with id = 2 from the list `a` has a value 5, and element with id = 4 from the list `b` also has a value 5.
// Combined, they add up to 10. Similarily, element with id = 3 from `a` has a value 7, and element with id = 2 from `b` has a value 3.
// These also add up to 10. Therefore, the optimal pairs are [2, 4] and [3, 2].

// a = {{1, 3}, {2, 5}, {3, 7}, {4, 10}}
// b = {{1, 2}, {2, 3}, {3, 4}, {4, 5}}


// Input:
// a = [[1, 8], [2, 7], [3, 14]]
// b = [[1, 5], [2, 10], [3, 14]]
// target = 20

// Output: [[3, 1]]

// a = {{1, 8}, {2, 7}, {3, 14}}
// b = {{1, 5}, {2, 10}, {3, 14}}

// Input:
// a = [[1, 8], [2, 15], [3, 9]]
// b = [[1, 8], [2, 11], [3, 12]]
// target = 20

// Output: [[1, 3], [3, 2]]

// a = {{1, 8}, {2, 15}, {3, 9}}
// b = {{1, 8}, {2, 11}, {3, 12}}
