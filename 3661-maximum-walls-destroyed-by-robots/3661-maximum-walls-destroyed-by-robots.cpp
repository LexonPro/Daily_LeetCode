#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        // Pair robots with their distances, sort by position
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = {robots[i], distance[i]};
        sort(arr.begin(), arr.end());
        sort(walls.begin(), walls.end());
        
        // Memo table: f[i][j]
        // i = robot index, j = direction next robot (to the right) fires (0=left, 1=right)
        vector<array<int,2>> f(n, {-1, -1});
        
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < 0) return 0;
            if (f[i][j] != -1) return f[i][j];
            
            // === Option 1: Robot i fires LEFT ===
            // Left boundary capped by previous robot's position
            int left = arr[i].first - arr[i].second;
            if (i > 0)
                left = max(left, arr[i-1].first + 1);
            
            int l = (int)(lower_bound(walls.begin(), walls.end(), left) - walls.begin());
            int r = (int)(lower_bound(walls.begin(), walls.end(), arr[i].first + 1) - walls.begin());
            int ans = dfs(i-1, 0) + (r - l);  // next robot (i-1) sees robot i firing left
            
            // === Option 2: Robot i fires RIGHT ===
            // Right boundary capped by next robot's position
            // If next robot fires left (j==0), its leftward bullet further restricts our range
            int right = arr[i].first + arr[i].second;
            if (i + 1 < n) {
                if (j == 0)
                    right = min(right, arr[i+1].first - arr[i+1].second - 1);
                else
                    right = min(right, arr[i+1].first - 1);
            }
            
            l = (int)(lower_bound(walls.begin(), walls.end(), arr[i].first) - walls.begin());
            r = (int)(lower_bound(walls.begin(), walls.end(), right + 1) - walls.begin());
            ans = max(ans, dfs(i-1, 1) + (r - l));  // next robot (i-1) sees robot i firing right
            
            return f[i][j] = ans;
        };
        
        // Start from rightmost robot, with no robot to its right (j=1 as default)
        return dfs(n-1, 1);
    }
};