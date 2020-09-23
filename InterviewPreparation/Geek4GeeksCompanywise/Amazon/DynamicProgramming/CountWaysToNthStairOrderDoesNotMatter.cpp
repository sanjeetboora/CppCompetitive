//Count ways to N'th Stair(Order does not matter)
//https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1
//https://stackoverflow.com/questions/62871148/count-ways-to-nth-stairorder-does-not-matter
class Solution {
public:

	int nthStair(int n) {
		//  Code here
		return n / 2 + 1;
	}
};