/*
1545. Find Kth Bit in Nth Binary String

Given two positive integers n and k, the binary string  Sn is formed as follows:

S1 = "0"
Si = Si-1 + "1" + reverse(invert(Si-1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).


Runtime: 1000 ms, faster than 6.98% of C++ online submissions for Find Kth Bit in Nth Binary String.
Memory Usage: 159.7 MB, less than 5.69% of C++ online submissions for Find Kth Bit in Nth Binary String.

*/
# include <iostream>
# include <vector>
# include <string>

using namespace std;

class Solution {
public:
	void invert(string &str) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '0') {
				str[i] = '1';
			}
			else {
				str[i] = '0';
			}
		}
	}
	char findKthBit(int n, int k) {
		vector<string> buf(n+1);
		buf[0] = "0";
		for (int i = 1; i <= n; i++) {
			string cur_str(buf[i - 1]);
			cur_str.push_back('1');
			string temp(buf[i - 1]);
			invert(temp);
			reverse(temp.begin(), temp.end());
			buf[i] = cur_str+temp;
		}
		return buf[n-1][k - 1];
	}
};

int main(void) {
	Solution sol = Solution();
	char result = sol.findKthBit(4,11);
	cout << "result: "<< result << endl;
}