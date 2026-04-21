class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
            parent[pa] = pb;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Step 1: Union
        for (auto &p : allowedSwaps) {
            unite(p[0], p[1]);
        }

        // Step 2: Count frequency
        unordered_map<int, unordered_map<int, int>> mp;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            mp[root][source[i]]++;
        }

        // Step 3: Match target
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            if (mp[root][target[i]] > 0) {
                mp[root][target[i]]--;
            } else {
                ans++;
            }
        }

        return ans;
    }
};