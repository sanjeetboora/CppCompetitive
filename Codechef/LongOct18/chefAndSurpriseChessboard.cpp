#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	nt** a = new int*[N];
	for (int i = 0; i < N; ++i) {
		a[i] = new int[M];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
		{
			cin>>a[i][j];
		}
	}
	return 0;
}