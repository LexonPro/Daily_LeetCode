class Solution {
public:

    bool isPrime(int x) {

        if (x < 2) return false;

        for (int i = 2; i * i <= x; i++) {

            if (x % i == 0)
                return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // store indices divisible by prime
        for (int i = 0; i < n; i++) {

            int x = nums[i];

            for (int d = 1; d * d <= x; d++) {

                if (x % d == 0) {

                    if (isPrime(d))
                        mp[d].push_back(i);

                    int other = x / d;

                    if (other != d && isPrime(other))
                        mp[other].push_back(i);
                }
            }
        }

        queue<int> q;

        vector<int> vis(n, 0);

        q.push(0);

        vis[0] = 1;

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int i = q.front();

                q.pop();

                if (i == n - 1)
                    return steps;

                // left
                if (i - 1 >= 0 && !vis[i - 1]) {

                    vis[i - 1] = 1;

                    q.push(i - 1);
                }

                // right
                if (i + 1 < n && !vis[i + 1]) {

                    vis[i + 1] = 1;

                    q.push(i + 1);
                }

                int val = nums[i];

                // teleport only if prime
                if (isPrime(val) && mp.count(val)) {

                    for (int idx : mp[val]) {

                        if (!vis[idx]) {

                            vis[idx] = 1;

                            q.push(idx);
                        }
                    }

                    // IMPORTANT
                    mp.erase(val);
                }
            }

            steps++;
        }

        return -1;
    }
};