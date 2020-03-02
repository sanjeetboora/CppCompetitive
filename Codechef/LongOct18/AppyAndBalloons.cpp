#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll fun(int N, ll M, ll* A, ll* B, pair<ll, int>*C) {
	ll low = C[0].first;
	ll high = C[N - 1].first;
	ll minimum = C[N - 1].first;
	while (low <= high) {
		ll mid = (low + high) / 2;
		//ll div = B[C[mid].second];
		ll balloons = M;
		ll maximum = INT_MIN;
		for (int i = N - 1; i >= 0; i--) {
			ll mul = C[i].first;
			ll num1 = A[C[i].second];
			ll num2 = B[C[i].second];
			ll edge = mid / num2;
			if (mid % num2 == 0) {
				edge--;
			}
			ll check = num2 * edge;
			//cout<<check<<endl;
			//cout<<edge<<endl;
			if (check < mul && balloons >= 0) {
				ll diff = mul - check;
				ll ball_use = diff / num2;
				if (ball_use > balloons && balloons > 0) {
					ball_use = balloons;
				} if (balloons - ball_use >= 0) {
					balloons = balloons - ball_use;
					num1 = num1 - ball_use;
				}
			}
			maximum = max(maximum, num1 * num2);
			//cout<<maximum<<endl;
		}
		minimum = min(maximum, minimum);
		//cout<<minimum<<endl;
		if (balloons <= 0) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
		//cout<<low<<" "<<high;

	}
	return minimum;
}
int main(int argc, char const *argv[])
{
	int N; ll M;
	cin >> N >> M;
	ll* A;
	A = new ll [N];
	ll* B;
	B = new ll [N];
	ll count = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		count += A[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	if (M >= count) {
		cout << 0 << endl;
		return 0;
	}
	pair<ll, int>*C;
	C = new pair<ll, int>[N];
	for (int i = 0; i < N; i++)
	{
		ll prod = A[i] * B[i];
		C[i] = make_pair(prod, i);
	}
	sort(C, C + N);
	cout << fun(N, M, A, B, C) << endl;
	return 0;
}