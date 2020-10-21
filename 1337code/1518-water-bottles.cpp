/*
1518. Water Bottles

Given numBottles full water bottles, you can exchange numExchange empty water bottles for one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Return the maximum number of water bottles you can drink.


Runtime: 0 ms, faster than 100.00% of C++ online submissions for Water Bottles.
Memory Usage: 5.9 MB, less than 85.52% of C++ online submissions for Water Bottles.

*/
#include <iostream>
using namespace std;

class Solution {
public:
	int numWaterBottles(int numBottles, int numExchange) {
		int currentBottles = numBottles;
		int emptyBottles = 0;
		int bottlesDrank = 0;

		//let's start with full bottles
		while (1) {
			// number of current bottles will be added to drank
			bottlesDrank += currentBottles;
           // number of bottles drank will be added to emptyBottles
			emptyBottles += currentBottles;
			// now redeem empty bottles to full
			currentBottles = (emptyBottles / numExchange);
			// leftover 
			emptyBottles = (emptyBottles % numExchange);
			if (emptyBottles + currentBottles < numExchange) {
				// take care of current undrank bottles
				bottlesDrank += currentBottles;
				break;
			}
		};
		return bottlesDrank;
	}

};

int main()
{
	Solution sol;
	int result;
	result = sol.numWaterBottles(15,4);
	cout << result << endl;
	return 0;

}

