//https://www.geeksforgeeks.org/minimum-rotations-required-get-string/

int rotations(string s1) {

	string temp = s1 + s1;
	int sz  = s1.length();

	for (int i = 1; i <= sz; i++) {

		string s = temp.substr(i, sz);
		if (s == s1) {
			return i;
		}
	}
	return n;
}