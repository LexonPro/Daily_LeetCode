class Solution {
public:
    static constexpr long long MOD = 1000000007;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);

        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int maxDepth = 0;

        function<void(int, int, int)> dfs = [&](int u, int p, int d) {
            maxDepth = max(maxDepth, d);
            for (int v : g[u]) {
                if (v != p) {
                    dfs(v, u, d + 1);
                }
            }
        };

        dfs(1, 0, 0);

        return (int)modPow(2, maxDepth - 1);
    }
};