/*
1043. Reverse Bits

Reverse bits of a given 32 bits unsigned integer.

Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.


*/
# include <iostream>
using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		// 1
		// 0000 0000 0000 0000 nnnn nnnn nnnn nnnn |
		// nnnn nnnn nnnn nnnn 0000 0000 0000 0000
		n = (n >> 16) | (n << 16);

		// 2.1
		// nnnn nnnn 0000 0000 nnnn nnnn 0000 0000 >> 8 = 
		// 0000 0000 nnnn nnnn 0000 0000 nnnn nnnn |
		// 2.2
		// 0000 0000 nnnn nnnn 0000 0000 nnnn nnnn >> 8 = 
		// nnnn nnnn 0000 0000 nnnn nnnn 0000 0000

		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);

		// 3.1
		// nnnn 0000 nnnn 0000 nnnn 0000 nnnn 0000 >> 4 = 
		// 0000 nnnn 0000 nnnn 0000 nnnn 0000 nnnn  |
		// 3.2
		// 0000 nnnn 0000 nnnn 0000 nnnn 0000 nnnn >> 4 = 
		// nnnn 0000 nnnn 0000 nnnn 0000 nnnn 0000

		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);

		// 3.1
		// nn00 nn00 nn00 nn00 nn00 nn00 nn00 nn00 >> 2 = 
		// 00nn 00nn 00nn 00nn 00nn 00nn 00nn 00nn  |
		// 3.2
		// 00nn 00nn 00nn 00nn 00nn 00nn 00nn 00nn >> 2 = 
		// 00nn 00nn 00nn 00nn 00nn 00nn 00nn 00nn

		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);

		// 4.1
		// n0n0 n0n0 n0n0 n0n0 n0n0 n0n0 n0n0 n0n0 >> 1 = 
		// 0n0n 0n0n 0n0n 0n0n 0n0n 0n0n 0n0n 0n0n  |
		// 4.2
		// 0n0n 0n0n 0n0n 0n0n 0n0n 0n0n 0n0n 0n0n >> 1 = 
		// n0n0 n0n0 n0n0 n0n0 n0n0 n0n0 n0n0 n0n0

		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}
};

int main(void) {
	Solution sol = Solution();
	uint32_t x = 1;
	x = sol.reverseBits(x);
	cout << x << endl;

}