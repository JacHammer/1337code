/*
191. Number of 1 Bits

Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.


*/
# include <iostream>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		for (int i = 0; i < 32; i++) {
			count += ((n & (1 << i)) >> i);
		}
		return count;
	}
};

int main(void) {
	Solution sol = Solution();
	uint32_t x = 1;
	x = sol.hammingWeight(x);
	cout << x << endl;

}