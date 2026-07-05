class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        // Start from S
        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;

                int best = -1;
                long long count = 0;

                // From below
                if (i + 1 < n && score[i + 1][j] != -1) {
                    if (score[i + 1][j] > best) {
                        best = score[i + 1][j];
                        count = ways[i + 1][j];
                    }
                    else if (score[i + 1][j] == best) {
                        count += ways[i + 1][j];
                    }
                }

                // From right
                if (j + 1 < n && score[i][j + 1] != -1) {
                    if (score[i][j + 1] > best) {
                        best = score[i][j + 1];
                        count = ways[i][j + 1];
                    }
                    else if (score[i][j + 1] == best) {
                        count += ways[i][j + 1];
                    }
                }

                // From diagonal
                if (i + 1 < n && j + 1 < n &&
                    score[i + 1][j + 1] != -1) {

                    if (score[i + 1][j + 1] > best) {
                        best = score[i + 1][j + 1];
                        count = ways[i + 1][j + 1];
                    }
                    else if (score[i + 1][j + 1] == best) {
                        count += ways[i + 1][j + 1];
                    }
                }

                if (best == -1) continue;

                int value = 0;

                if (board[i][j] != 'E') {
                    value = board[i][j] - '0';
                }

                score[i][j] = best + value;
                ways[i][j] = count % MOD;
            }
        }

        if (score[0][0] == -1) {
            return {0, 0};
        }

        return {score[0][0], ways[0][0]};
    }
};