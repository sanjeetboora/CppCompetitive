#include<bits/stdc++.h>
#define ll long long int
using namespace std;

double dis(double x1, double y1, double x2, double y2) {
	double x = x1 - x2;
	double y = y1 - y2;
	double dist;
	dist = (x * x) + (y * y);
	dist = sqrt(dist);
	return dist;
}
int main(int argc, char const *argv[])
{
	int N, Q;
	cin >> N >> Q;
	pair<pair<double, double>, double>* arr = new pair<pair<double, double>, double>[N];//<x,y>,radius
	pair<pair<int, int>, double>* distance = new pair<pair<int, int>, double> [N * N]; //<idx1,idx2><mindis,maxdis>
	ll disarr[1000006] = {0};
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first.first;
		cin >> arr[i].first.second;
		cin >> arr[i].second;
	}
	ll k = 0;

	for (int i = 0; i < N ; i++)
	{
		for (int j = i+1; j < N; j++)
		{	if (i == j) {
				continue;
			}
			double min = 0, max = 0;
			double x1 = arr[i].first.first, y1 = arr[i].first.second, x2 = arr[j].first.first, y2 = arr[j].first.second;
			double r1 = arr[i].second, r2 = arr[j].second;
			double dist = dis(x1, y1, x2, y2);
			double bigRad = r1 > r2 ? r1 : r2;
			double smallRad = r1 < r2 ? r1 : r2;
			if (x1 == x2 && y1 == y2) { // concentric circles
				min = (bigRad - smallRad);
				max = min;
			}
			else { // non- concentric
                if (dist > (r1 + r2)) // circles don't overlap or intersect
                {
                    min = dist - r1 - r2;
                    max = dist + r1 + r2;
                }
                else if (dist < bigRad - smallRad) // smaller  is properly inside bigger circle
                {
                    min = bigRad - dist - smallRad;
                    max = bigRad + dist + smallRad;
                }
                else if (dist == (r1 + r2))
                {
                    min = 0;
                    max = (2 * r1 + 2 * r2);
                }
                else
                {
                    min = 0;
                    max = (dist + r1 + r2);
                }
			}
			int minval = ceil(min);
			int maxval = floor(max);
			disarr[minval] += 1;
			disarr[maxval + 1] -= 1;
			k++;
		}
	}
	for (int i = 1; i < 1000006; i++) {
		disarr[i] = disarr[i] + disarr[i - 1];
        //cout<<i<<" -> "<<disarr[i]<<endl;
	}
	for (int i = 0; i < Q; i++)
	{
		ll K;
		cin >> K;
		ll count = disarr[K];	
		cout << count << endl;
	}
	return 0;
}
