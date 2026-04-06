class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: North, East, South, West
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        int d = 0; // direction index
        int x = 0, y = 0;
        int maxDist = 0;
        
        // Store obstacles
        set<pair<int,int>> obs;
        for(auto &o : obstacles) {
            obs.insert({o[0], o[1]});
        }
        
        for(int cmd : commands) {
            if(cmd == -1) {
                d = (d + 1) % 4; // turn right
            }
            else if(cmd == -2) {
                d = (d + 3) % 4; // turn left
            }
            else {
                for(int i = 0; i < cmd; i++) {
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;
                    
                    if(obs.count({nx, ny})) break;
                    
                    x = nx;
                    y = ny;
                    
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        
        return maxDist;
    }
};