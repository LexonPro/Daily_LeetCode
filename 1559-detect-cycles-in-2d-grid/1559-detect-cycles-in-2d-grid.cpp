#include <vector>

using namespace std;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid, visited, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool dfs(int r, int c, int pr, int pc, vector<vector<char>>& grid, vector<vector<bool>>& visited, char target) {
        visited[r][c] = true;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) continue;
            if (grid[nr][nc] != target) continue;
            if (nr == pr && nc == pc) continue;
            if (visited[nr][nc]) return true;
            if (dfs(nr, nc, r, c, grid, visited, target)) return true;
        }

        return false;
    }
};