#include<bits/stdc++.h>
using namespace std;

void pairTutoial() {
	//pair

	pair<int, string> p;

	p.first = 100;
	p.second = "Hi";
	cout << p.first << ", " << p.second << endl;

//------------------------------------------------------------

	pair<string , int> p2("Hi", 100);
	cout << p2.first << ", " << p2.second << endl;

//------------------------------------------------------------

	pair<string , int> p3 = {"Hi", 100};
	cout << p3.first << ", " << p3.second << endl;
//------------------------------------------------------------

	pair<string , int> p4 = make_pair("Hi", 100);
	cout << p4.first << ", " << p4.second << endl;
//------------------------------------------------------------

	pair<int, string> arr[10] = {{1, "one"}, {3, "three"}, {2, "two"}};
	for (int i = 0; i < 3; ++i)
	{
		cout << arr[i].first << ", " << arr[i].second << endl;
	}
}

void arrayTutorial() {
	array<int, 10> arr;
	array<int, 10> :: iterator it = arr.begin();
	cout << *(it) << endl;

	for (array<int, 10> :: iterator it = arr.begin(); it != arr.end(); it++) {
		*(it) = 10;
		cout << *(it) << endl;
	}
//------------------------------------------------------------
	array<int, 10> arr1 = {1, 2, 3, 4, 5};

	for (auto it = arr1.begin(); it != arr1.end(); it++) {
		cout << *(it) << endl;
	}
//------------------------------------------------------------
	array<int, 10> arr2 = {100};

	for (auto it : arr2) {
		cout << it << endl;
	}

}


void vectorTutorial() {
	vector<int> v;
	v.push_back(1);
	v.emplace_back(5);

	for (auto i : v) {
		cout << i << ",";
	} cout << endl;
//------------------------------------------------------------

	vector<pair<int, int> > v1;
	//v1.push_back(1, 2); -> error
	v1.push_back({1, 2});
	v1.push_back(make_pair(1, 2));
	v1.emplace_back(3, 4);
	for (auto i : v1) {
		cout << i.first << "," << i.second << endl;
	}
//------------------------------------------------------------

	vector<int> v2(5, 100); // {100, 100, 100, 100, 100}
	for (auto i : v2) {
		cout << i << ",";
	} cout << endl;

//------------------------------------------------------------
	v2[0] = 120;
	for (auto i : v2) {
		cout << i << ",";
	} cout << endl;
	//v2.erase(v2.begin());

	v2.erase(v2.begin(), v2.begin() + 3);
	for (auto i : v2) {
		cout << i << ",";
	} cout << endl;
}





int main(int argc, char const * argv[])
{
	//pairTutoial();
	//arrayTutorial();
	vectorTutorial();
	cout << endl;

	return 0;
}
