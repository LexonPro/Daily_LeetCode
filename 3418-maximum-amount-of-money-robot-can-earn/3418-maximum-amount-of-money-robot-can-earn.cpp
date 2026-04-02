#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[i][j][k] -> max coins at (i, j) with k neutralizations REMAINING
        // Initializing with a very small number to represent unvisited/impossible
        long long INF = 1e15;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, -INF)));

        // Base case: Starting at (0,0)
        if (coins[0][0] < 0) {
            dp[0][0][2] = coins[0][0]; // Don't use neutralization
            dp[0][0][1] = 0;            // Use 1 neutralization
        } else {
            dp[0][0][2] = coins[0][0]; // Gain coins, neutralizations stay at 2
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k <= 2; ++k) {
                    long long prev_max = -INF;
                    if (i > 0) prev_max = max(prev_max, dp[i-1][j][k]);
                    if (j > 0) prev_max = max(prev_max, dp[i][j-1][k]);

                    if (prev_max == -INF) continue;

                    if (coins[i][j] >= 0) {
                        // Just add the coins
                        dp[i][j][k] = max(dp[i][j][k], prev_max + coins[i][j]);
                    } else {
                        // Option 1: Don't neutralize, take the robbery hit
                        dp[i][j][k] = max(dp[i][j][k], prev_max + coins[i][j]);
                        
                        // Option 2: Use one neutralization (if any left)
                        if (k > 0) {
                            dp[i][j][k-1] = max(dp[i][j][k-1], prev_max);
                        }
                    }
                }
            }
        }

        // Result is the max of having 0, 1, or 2 neutralizations left at the destination
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};