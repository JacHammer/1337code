/*
1356. Sort Integers by The Number of 1 Bits

Given an integer array arr. You have to sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the sorted array.



Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]

*/

# include <iostream>
# include <vector>
# include <algorithm>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

using namespace std;

class Solution {
public:
	static bool compareBit(const int& i, const int& j) {
		int i_count = __builtin_popcount(i);
		int j_count = __builtin_popcount(j);
		if (i_count == j_count)
			return i < j;
		return i_count < j_count;
	}

	vector<int> sortByBits(vector<int> & arr) {
		sort(arr.begin(), arr.end(), compareBit);
		return arr;
	}

};

int main(void) {
	Solution sol = Solution();
	vector<int> arr = { 2,3,5,7,11,13,17,19 };
	arr = sol.sortByBits(arr);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ',';
	}
	cout << endl;
}