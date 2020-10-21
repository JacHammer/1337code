/*
215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
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
	int findKthLargest(vector<int>& nums, int k) {
		std::sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};

int main(void) {
	Solution sol = Solution();
	vector<int> arr = { 3,2,1,5,6,4 };
	int result = sol.findKthLargest(arr, 2);
	cout << result;
	cout << endl;
	return 0;
}