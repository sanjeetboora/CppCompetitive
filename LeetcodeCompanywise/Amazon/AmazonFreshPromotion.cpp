#include <bits/stdc++.h>
using namespace std;

int winner(vector<vector<string> > codeList, vector<string> shoppingCart ) {
	int i = 0, j = 0;
	while (i < codeList.size() and j + codeList[i].size() <= shoppingCart.size() ) {
		bool perfectMatch = true;
		for (int k = 0; k < codeList[i].size(); k++)
		{
			if (codeList[i][k] != "anything" and codeList[i][k] != shoppingCart[j + k]) {
				perfectMatch = false;
				break;
			}
		}
		if (perfectMatch) {
			j += codeList[i].size();
			i++;
		} else {
			j++;
		}
	}
	return i == codeList.size() ? 1 : 0;
}


int main(int argc, char const *argv[])
{

	int s;
	cin >> s;
	vector<vector<string> > codeList;
	for (int i = 0; i < s; ++i)
	{	int n;
		cin >> n;
		vector<string> v;
		for (int i = 0; i < n ; ++i)
		{
			string str;
			cin >> str;
			v.push_back(str);
		}
		codeList.push_back(v);
	}

	vector<string> shoppingCart;
	int x;
	cin >> x;
	for (int i = 0; i < x; ++i)
	{
		string str;
		cin >> str;
		shoppingCart.push_back(str);
	}

	cout << winner(codeList, shoppingCart) << endl;


	return 0;
}


// codeList = [apple, apple], [banana, anything, banana]] shoppingCart = [orange, apple, apple, banana, orange, banana]
// 2 2 apple apple 3 banana anything banana 6 orange apple apple banana orange banana

//codeList = [[apple, apple], [banana, anything, banana]] shoppingCart = [banana, orange, banana, apple, apple]
// 2 2 apple apple 3 banana anything banana 5 banana orange banana apple apple

//codeList = [[apple, apple], [banana, anything, banana]] shoppingCart = [apple, banana, apple, banana, orange, banana]
// 2 2 apple apple 3 banana anything banana 6 apple banana apple banana orange banana

// codeList = [[apple, apple], [apple, apple, banana]] shoppingCart = [apple, apple, apple, banana]
// 2 3 apple apple 3 apple apple banana 4 apple apple apple banana



