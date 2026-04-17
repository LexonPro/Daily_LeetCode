#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Helper to reverse digits as per the problem (120 -> 21)
    int getReverse(int n) {
        long long rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        // Constraints say nums[i] <= 10^9, so reversed will fit in int
        return (int)rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        // Map stores: key = reverse(nums[i]), value = latest index i
        unordered_map<int, int> lastSeenReverse;
        int minDistance = INT_MAX;

        for (int j = 0; j < nums.size(); ++j) {
            // If the current number matches a previously stored reverse(nums[i])
            if (lastSeenReverse.count(nums[j])) {
                minDistance = min(minDistance, j - lastSeenReverse[nums[j]]);
            }

            // We store the reverse of the current number to be found by a future nums[k]
            // We only care about the LATEST index of a specific reverse value 
            // because that will always yield the smallest distance for future matches.
            lastSeenReverse[getReverse(nums[j])] = j;
        }

        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};