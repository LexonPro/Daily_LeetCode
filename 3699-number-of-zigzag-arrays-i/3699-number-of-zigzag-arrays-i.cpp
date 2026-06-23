class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> up(m, 1), down(m, 1);
        vector<long long> newUp(m), newDown(m);
        vector<long long> prefUp(m + 1), prefDown(m + 1);

        for (int len = 2; len <= n; len++) {
            prefUp[0] = prefDown[0] = 0;

            for (int i = 0; i < m; i++) {
                prefUp[i + 1] = (prefUp[i] + up[i]) % MOD;
                prefDown[i + 1] = (prefDown[i] + down[i]) % MOD;
            }

            for (int x = 0; x < m; x++) {
                newUp[x] = prefDown[x];
                newDown[x] =
                    (prefUp[m] - prefUp[x + 1] + MOD) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};