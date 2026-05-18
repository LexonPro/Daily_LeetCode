class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int idx = q.front();
                q.pop();

                if(idx == n - 1) return steps;

                vector<int> next = mp[arr[idx]];
                next.push_back(idx - 1);
                next.push_back(idx + 1);

                for(int x : next) {
                    if(x >= 0 && x < n && !vis[x]) {
                        vis[x] = true;
                        q.push(x);
                    }
                }

                mp[arr[idx]].clear();
            }

            steps++;
        }

        return -1;
    }
};