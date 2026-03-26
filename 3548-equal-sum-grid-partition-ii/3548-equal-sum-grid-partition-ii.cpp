class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                total += grid[i][j];
 
        if (checkHorizontal(grid, m, n, total)) return true;
        return checkVertical(grid, m, n, total);
    }
 
private:
    // A cell in a section of (rows x cols) can be removed keeping connectivity iff:
    //   rows >= 2 AND cols >= 2  ->  any cell is safe
    //   otherwise (single row or single col)  ->  only the two end-corner cells are safe
 
    bool checkHorizontal(vector<vector<int>>& grid, int m, int n, long long total) {
        vector<long long> rowSum(m, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                rowSum[i] += grid[i][j];
 
        unordered_map<int,int> suffCnt;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                suffCnt[grid[i][j]]++;
 
        unordered_map<int,int> topCnt;
        long long topSum = 0;
 
        for (int r = 0; r < m - 1; r++) {
            for (int j = 0; j < n; j++) {
                int v = grid[r][j];
                topCnt[v]++;
                if (--suffCnt[v] == 0) suffCnt.erase(v);
            }
            topSum += rowSum[r];
            long long botSum = total - topSum;
 
            if (topSum == botSum) return true;
 
            long long diff = topSum - botSum;
            int topRows = r + 1;
            int botRows = m - r - 1;
 
            // Remove from top: value must equal diff
            if (diff > 0 && diff <= 100000) {
                int v = (int)diff;
                if (topRows >= 2 && n >= 2) {
                    // any cell removable
                    if (topCnt.count(v)) return true;
                } else {
                    // single row (topRows==1) or single col (n==1): only corners
                    // corners of top section: [0][0], [0][n-1], [r][0], [r][n-1]
                    if (grid[0][0] == v || grid[0][n-1] == v ||
                        grid[r][0] == v || grid[r][n-1] == v) return true;
                }
            }
 
            // Remove from bottom: value must equal -diff
            if (diff < 0 && -diff <= 100000) {
                int v = (int)(-diff);
                if (botRows >= 2 && n >= 2) {
                    if (suffCnt.count(v)) return true;
                } else {
                    // corners of bottom section: [r+1][0], [r+1][n-1], [m-1][0], [m-1][n-1]
                    if (grid[r+1][0] == v || grid[r+1][n-1] == v ||
                        grid[m-1][0] == v || grid[m-1][n-1] == v) return true;
                }
            }
        }
        return false;
    }
 
    bool checkVertical(vector<vector<int>>& grid, int m, int n, long long total) {
        vector<long long> colSum(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                colSum[j] += grid[i][j];
 
        unordered_map<int,int> suffCnt;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                suffCnt[grid[i][j]]++;
 
        unordered_map<int,int> leftCnt;
        long long leftSum = 0;
 
        for (int c = 0; c < n - 1; c++) {
            for (int i = 0; i < m; i++) {
                int v = grid[i][c];
                leftCnt[v]++;
                if (--suffCnt[v] == 0) suffCnt.erase(v);
            }
            leftSum += colSum[c];
            long long rightSum = total - leftSum;
 
            if (leftSum == rightSum) return true;
 
            long long diff = leftSum - rightSum;
            int leftCols = c + 1;
            int rightCols = n - c - 1;
 
            // Remove from left: value must equal diff
            if (diff > 0 && diff <= 100000) {
                int v = (int)diff;
                if (m >= 2 && leftCols >= 2) {
                    if (leftCnt.count(v)) return true;
                } else {
                    // corners of left section: [0][0], [m-1][0], [0][c], [m-1][c]
                    if (grid[0][0] == v || grid[m-1][0] == v ||
                        grid[0][c] == v || grid[m-1][c] == v) return true;
                }
            }
 
            // Remove from right: value must equal -diff
            if (diff < 0 && -diff <= 100000) {
                int v = (int)(-diff);
                if (m >= 2 && rightCols >= 2) {
                    if (suffCnt.count(v)) return true;
                } else {
                    // corners of right section: [0][c+1], [m-1][c+1], [0][n-1], [m-1][n-1]
                    if (grid[0][c+1] == v || grid[m-1][c+1] == v ||
                        grid[0][n-1] == v || grid[m-1][n-1] == v) return true;
                }
            }
        }
        return false;
    }
};