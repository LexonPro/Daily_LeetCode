class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        auto toLinear = [&](int x, int y) -> long long {
            if (y == 0) return x;
            if (x == side) return (long long)side + y;
            if (y == side) return 2LL * side + (side - x);
            return 3LL * side + (side - y);
        };

        int n = points.size();
        vector<long long> pos(n);
        for (int i = 0; i < n; i++)
            pos[i] = toLinear(points[i][0], points[i][1]);
        sort(pos.begin(), pos.end());

        long long perimeter = 4LL * side;
        int N = 2 * n;

        vector<long long> pos2(N);
        for (int i = 0; i < n; i++) {
            pos2[i]     = pos[i];
            pos2[i + n] = pos[i] + perimeter;
        }

        const int LOG = 5; // 2^5 = 32 >= k_max = 25

        auto check = [&](long long mid) -> bool {
            vector<int> nxt(N, N);
            {
                int j = 0;
                for (int i = 0; i < N; i++) {
                    if (j <= i) j = i + 1;
                    while (j < N && pos2[j] - pos2[i] < mid) j++;
                    nxt[i] = j;
                }
            }

            // Binary lifting table
            vector<array<int, 30001>> lift; // too large on stack, use vector
            // Use flat 2D
            vector<vector<int>> jump(LOG + 1, vector<int>(N, N));
            jump[0] = nxt;
            for (int lv = 1; lv <= LOG; lv++)
                for (int i = 0; i < N; i++)
                    if (jump[lv-1][i] < N)
                        jump[lv][i] = jump[lv-1][jump[lv-1][i]];

            for (int s = 0; s < n; s++) {
                int cur = s;
                bool ok = true;
                int rem = k - 1;
                for (int lv = LOG; lv >= 0; lv--) {
                    if (rem >= (1 << lv)) {
                        cur = jump[lv][cur];
                        rem -= (1 << lv);
                        if (cur >= N) { ok = false; break; }
                    }
                }
                if (!ok) continue;
                long long wrap = pos2[s] + perimeter - pos2[cur];
                if (wrap >= mid) return true;
            }
            return false;
        };

        long long lo = 0, hi = perimeter / k, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (check(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return (int)ans;
    }
};