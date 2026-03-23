class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        // dpMax[i][j] = max product path to (i, j)
        // dpMin[i][j] = min product path to (i, j)
        vector<vector<long long>> dpMax(m, vector<long long>(n, 0));
        vector<vector<long long>> dpMin(m, vector<long long>(n, 0));

        // ── Base case: top-left corner ──
        dpMax[0][0] = dpMin[0][0] = grid[0][0];

        // ── Fill first column (can only come from above) ──
        for (int i = 1; i < m; i++) {
            dpMax[i][0] = dpMin[i][0] = dpMax[i-1][0] * grid[i][0];
        }

        // ── Fill first row (can only come from left) ──
        for (int j = 1; j < n; j++) {
            dpMax[0][j] = dpMin[0][j] = dpMax[0][j-1] * grid[0][j];
        }

        // ── Fill rest of the grid ──
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long g = grid[i][j];

                // All 4 candidates from top and left
                long long c1 = dpMax[i-1][j] * g;
                long long c2 = dpMin[i-1][j] * g;
                long long c3 = dpMax[i][j-1] * g;
                long long c4 = dpMin[i][j-1] * g;

                dpMax[i][j] = max({c1, c2, c3, c4});
                dpMin[i][j] = min({c1, c2, c3, c4});
            }
        }

        long long ans = dpMax[m-1][n-1];

        // Return -1 if max product is negative, else return with mod
        return ans < 0 ? -1 : ans % MOD;
    }
};