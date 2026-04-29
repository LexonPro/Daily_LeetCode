class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        const int n = grid.size();

        // prefix[j][i] = sum of first i rows in column j
        vector<vector<long long>> prefix(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < n; ++i)
                prefix[j][i + 1] = prefix[j][i] + grid[i][j];

        // prevPick[i]: best score so far, prev column cut at depth i (was selected/black)
        // prevSkip[i]: best score so far, prev column cut at depth i (was skipped/white)
        vector<long long> prevPick(n + 1, 0), prevSkip(n + 1, 0);

        for (int j = 1; j < n; ++j) {
            vector<long long> currPick(n + 1, 0), currSkip(n + 1, 0);

            for (int curr = 0; curr <= n; ++curr) {
                for (int prev = 0; prev <= n; ++prev) {
                    if (curr > prev) {
                        // Current column is deeper black than previous.
                        // Rows [prev, curr) in column j-1 are white with black neighbor (col j).
                        // Score those cells from col j-1 (which was white = skipped).
                        long long score = prefix[j - 1][curr] - prefix[j - 1][prev];
                        currPick[curr] = max(currPick[curr], prevSkip[prev] + score);
                        currSkip[curr] = max(currSkip[curr], prevSkip[prev] + score);
                    } else {
                        // Previous column is deeper black than current.
                        // Rows [curr, prev) in column j are white with black neighbor (col j-1).
                        // Score those cells from col j (current column is white = skipped).
                        long long score = prefix[j][prev] - prefix[j][curr];
                        currPick[curr] = max(currPick[curr], prevPick[prev] + score);
                        // Skip: no new score from col j-1 side for the skipped column
                        currSkip[curr] = max(currSkip[curr], prevPick[prev]);
                    }
                }
            }

            prevPick = move(currPick);
            prevSkip = move(currSkip);
        }

        return *max_element(prevPick.begin(), prevPick.end());
    }
};