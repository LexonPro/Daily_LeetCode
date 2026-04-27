class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<vector<int>>> dirs = {
            {},
            {{0,-1},{0,1}},
            {{-1,0},{1,0}},
            {{0,-1},{1,0}},
            {{0,1},{1,0}},
            {{0,-1},{-1,0}},
            {{0,1},{-1,0}}
        };
        
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        
        q.push({0,0});
        vis[0][0] = true;
        
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            
            if(x == m-1 && y == n-1) return true;
            
            for(auto &d : dirs[grid[x][y]]) {
                int nx = x + d[0];
                int ny = y + d[1];
                
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny]) continue;
                
                // check reverse connection
                for(auto &back : dirs[grid[nx][ny]]) {
                    if(nx + back[0] == x && ny + back[1] == y) {
                        vis[nx][ny] = true;
                        q.push({nx,ny});
                        break;
                    }
                }
            }
        }
        
        return false;
    }
};