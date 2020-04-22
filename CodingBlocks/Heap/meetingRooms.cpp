#include <bits/stdc++.h>
using namespace std;


int rooms(vector<vector<int> >meetings) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >minStart;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >minEnd;

	int num = meetings.size();
	int i = 0;
	while (i < num) {
		minStart.push(make_pair(meetings[i][0], meetings[i][1]));
		i++;
	}
	int reqroom = 0;

	if (!minStart.empty()) {
		minEnd.push(make_pair(minStart.top().second, minStart.top().first));
		minStart.pop();
		reqroom++;
	}

	while (!minStart.empty()) {
		pair<int, int> curr = minStart.top();
		minStart.pop();
		if (curr.first < minEnd.top().first) {
			minEnd.push(make_pair(curr.second, curr.first));
			int s = minEnd.size();
			reqroom = max(reqroom, s);
		}
		else {
			while (!minStart.empty() and !minEnd.empty() and minStart.top().first >= minEnd.top().first) {
				minEnd.pop();
			} minEnd.push(make_pair(curr.second, curr.first));
		}
	}
	return reqroom;

}



int main(int argc, char const *argv[])
{	
	vector<vector<int> > v {{0, 30},
							{5, 10},
							{15, 20}};

	int result = rooms(v);
	cout<<result<<endl;

	return 0;
}