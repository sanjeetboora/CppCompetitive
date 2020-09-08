#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{

//Initialization

	string str;
	string str1("Hi Mithu!");
	string str2 = "Hi Mithu!";

//shallow copy constructor
	string str3(str2);
	cout << "str3 => " << str3 << endl;
	str2[1] = 'y';
	cout << "str2 => " << str2 << endl;
	cout << "str3 => " << str3 << endl;

	string str4 = str3;

	char arr[] = {'a', 'b', 'c', 'd', '\0'};

	string str5(arr);
	cout << "str5 => " << str5 << endl;

	if (str.empty()) {
		cout << "str is empty" << endl;
	}


//Append
	str.append("I love mithu");
	cout << "str => " << str << endl;

	str1 += " How are you?";
	cout << "str1 => " << str1 << endl;


//Remove
	cout << "str.length() => " << str.length() << endl;
	str.clear();
	cout << "str.length() => " << str.length() << endl;

//Compare two strings
	str = "Mithii";
	str1 = "Mithu";
	cout << "str.compare(str1) => " << str.compare(str1) << endl;;

	//compare() will return an integer 0 if str == str1
	//compare() will return a -ve integer if str < str1
	//compare() will return a +ve integer if str > str1


//Overloaded Operator operators
	if (str1 > str) {
		cout << str1 << " is greater than " << str << endl;
	}
	else if (str1 < str) {
		cout << str1 << " is less than " << str << endl;
	}


	cout << str[1] << endl;

// find substring
	str = "I love mithu";
	string word = "mithu";
	int idx = str.find(word);
	cout << word << " found at index " << idx << endl;

//remove substring
	str.erase

	return 0;
}





