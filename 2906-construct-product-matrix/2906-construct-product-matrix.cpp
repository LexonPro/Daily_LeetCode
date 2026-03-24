class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size = n * m;
        const int MOD = 12345;

        vector<int> arr(size);

        // Step 1: flatten
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i * m + j] = grid[i][j] % MOD;
            }
        }

        // Step 2: prefix
        vector<int> prefix(size, 1);
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD;
        }

        // Step 3: suffix
        vector<int> suffix(size, 1);
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD;
        }

        // Step 4: result
        vector<vector<int>> result(n, vector<int>(m));

        for (int i = 0; i < size; i++) {
            int val = (prefix[i] * suffix[i]) % MOD;
            result[i / m][i % m] = val;
        }

        return result;
    }
};