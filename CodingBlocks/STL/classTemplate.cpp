#include<bits/stdc++.h>
using namespace std;

//generic programming
template< typename T, typename U>
class Pair
{
public:
	T first;
	U second;
	Pair() {};
	Pair(T a, U b) {
		first = a;
		second = b;
	}


};

int main(int argc, char const *argv[])
{
	Pair<int , string> p;
	p.first = 10;
	p.second = "abc";
	cout << p.first << ", " << p.second << endl;

	Pair<string , int> p2("Hi", 100);
	cout << p2.first << ", " << p2.second << endl;

	return 0;
}