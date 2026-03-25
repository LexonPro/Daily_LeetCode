class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return false;

        int m = grid.size();
        int n = grid[0].size();
        
        // Use long long to prevent overflow with large grid values
        long long total = 0;
        vector<long long> rowSums(m, 0);
        vector<long long> colSums(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSums[i] += grid[i][j];
                colSums[j] += grid[i][j];
                total += grid[i][j];
            }
        }

        // Optimization: If total is odd, it's impossible to split into two equal integers
        if (total % 2 != 0) return false;
        long long target = total / 2;

        // Check horizontal cuts
        long long rowPrefix = 0;
        for (int i = 0; i < m - 1; i++) {
            rowPrefix += rowSums[i];
            if (rowPrefix == target) return true;
        }

        // Check vertical cuts
        long long colPrefix = 0;
        for (int j = 0; j < n - 1; j++) {
            colPrefix += colSums[j];
            if (colPrefix == target) return true;
        }

        return false;
    }
};