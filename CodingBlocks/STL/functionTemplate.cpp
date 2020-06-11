#include<bits/stdc++.h>
using namespace std;


template<typename T>

T add(T a, T b) {
	return a + b;
}

int main(int argc, char const *argv[])
{
	int a = 5, b = 10;
	string s1 = "abc", s2 = "efg";
	int sum = add(a, b);
	string concatinate = add(s1, s2);

	cout << sum << endl;
	cout << concatinate << endl;
	cout << add(s1, s2) << endl;

	//using explicit template types

	int sum1 = add<int>(a, b);
	string concatinate1 = add<string>(s1, s2);
	cout << sum1 << endl;
	cout << concatinate1 << endl;
	cout << add<string>(s1, s2) << endl;
	cout << add<double>(a, b) << endl;
	auto sum2 = add(a, b);
	cout << sum2 << endl;

	return 0;
}