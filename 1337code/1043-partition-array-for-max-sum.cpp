/*
1043. Partition Array for Maximum Sum

Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.


*/
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& A, int K) {
		int N = A.size();
		vector<int> dp(N);
		for (int i = 0; i < N; ++i) {
			int curMax = 0;
			for (int k = 1; k <= K && i - k + 1 >= 0; ++k) {
				curMax = max(curMax, A[i - k + 1]);
				dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + curMax * k);
				for (int curr = 0; curr < N; curr++) {
					cout << dp[curr] << '|';
				}
				cout << endl;
			}
		}
		return dp[N - 1];
	}


};

int main(void) {
	Solution sol = Solution();
	vector<int> v = {1, 15, 7, 9, 2, 5, 10};
	int result = sol.maxSumAfterPartitioning(v, 3);
	cout << result << endl;

}