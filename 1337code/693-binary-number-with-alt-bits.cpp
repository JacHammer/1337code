/*
693. Binary Number with Alternating Bits
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:

Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101

*/
# include <iostream>
using namespace std;

class Solution {
public:
	bool hasAlternatingBits(int n) {
		int last_bit = n & 1;
		while (n) {
			n = n >> 1;
			if (last_bit == (n & 1)) {
				return false;
			}
			last_bit = n & 1;
		}
		return true;
	}
};

int main(void) {
	Solution sol = Solution();
	int  x = 4;
	x = sol.hasAlternatingBits(x);
	cout << x << endl;

}