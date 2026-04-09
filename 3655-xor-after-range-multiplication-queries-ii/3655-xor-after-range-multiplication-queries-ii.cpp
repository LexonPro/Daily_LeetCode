class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int T = sqrt(n);

        vector<vector<vector<int>>> groups(T);

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= T) {
                for (int i = l; i <= r; i += k)
                    nums[i] = (1LL * nums[i] * v) % MOD;
            } else {
                groups[k].push_back({l, r, v});
            }
        }

        vector<long long> diff(n + T);

        for (int k = 1; k < T; k++) {
            if (groups[k].empty()) continue;

            fill(diff.begin(), diff.end(), 1);

            for (auto &q : groups[k]) {
                int l = q[0], r = q[1], v = q[2];

                diff[l] = diff[l] * v % MOD;

                int stop = l + ((r - l) / k + 1) * k;
                if (stop < n)
                    diff[stop] = diff[stop] * modPow(v, MOD - 2) % MOD;
            }

            for (int i = k; i < n; i++)
                diff[i] = diff[i] * diff[i - k] % MOD;

            for (int i = 0; i < n; i++)
                nums[i] = (nums[i] * diff[i]) % MOD;
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};