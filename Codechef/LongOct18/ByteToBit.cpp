/* Problem -  */
/* By Sanjeet Boora */

#include <iostream>
using namespace std;
void print(long long int arr[]) {
	cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
}
int main(int argc, char const *argv[])
{
	// TODO Auto-generated method stub

	long long int test;
	cin >> test;

	for (long i = 0; i < test; i++) {
		long long int arr[3] = {0};
		arr[0] = 1;

		long long int num;
		cin >> num;
		if (num == 0) {
			print(arr);
			continue;
		}
		long long int count = 0, total = 0;
//			else if (num % 16 < 2) {
//				print(arr);
//				arr[0] = 2 * (num / 16);
//				arr[2] = 0;
//				arr[1] = 0;
//			} else if (num % 16 >= 2 && num % 16 < 8) {
//				print(arr);
//				arr[0] = 2 * (num/16);
//				arr[1] = 1;
//				arr[2] = 0;
//
//			} else if (num % 16 >= 8 && num % 16 < 16) {
//				print(arr);
//				arr[0] = 2 * (num / 16);
//				arr[1] = 0;
//				arr[2] = 1;
//			}
		for (total = 0L; total < num;) {
			for (count = 0; total < num && count < 2; total++, count++) {

			}
			if (total == num) {
				print(arr);
				continue;
			} else {
				arr[1] = arr[0];
				arr[0] = 0;
			}
			for (count = 0; total < num && count < 8; total++, count++) {

			}
			if (total == num) {
				print(arr);
				continue;
			} else {
				arr[2] = arr[1];
				arr[1] = 0;
			}
			for (count = 0; total < num && count < 16; total++, count++) {

			}
			if (total == num) {
				print(arr);
				continue;
			} else {
				arr[0] = 2 * arr[2];
				arr[2] = 0;
			}
		}
	}
	return 0;
}



