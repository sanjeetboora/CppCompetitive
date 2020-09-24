// https://www.geeksforgeeks.org/ola-interview-experience-set-15-1-year-experienced-for-sde1/
#include <bits/stdc++.h>
using namespace std;
//Time: O(N) | Space: O(N)
bool isPossible(string s1, string s2) {

	string sm1 = "", sm2 = "";

	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != '#') {
			sm1 += s1[i];
		}
	}
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] != '#') {
			sm2 += s2[i];
		}
	}

	return sm1 == sm2;
}

//Time: O(N) | Space: O(1)
bool isPossible2(string s1, string s2) {


	int i = 0, j = 0;

	while (i < s1.length()) {
		char x = s1[i];
		if (x != '#') {
			if (j == s2.length()) {
				return false;
			}
			else {
				while (j < s2.length()) {
					if (s2[j] != '#') {
						if (s2[j] == x) {
							j++;
							break;
						} else {
							return false;
						}
					}
					j++;
				}
			}
		}
		i++;
	}

	while (j < s2.length()) {
		if (s2[j] != '#') {
			return false;
		}
		j++;
	}

	return true;
}

int main(int argc, char const *argv[])
{
	string s1 = "#B#A#";
	string s2 = "#B#A#B#";
	cout << isPossible(s1, s2) << endl;
	cout << isPossible2(s1, s2) << endl;
	return 0;
}




