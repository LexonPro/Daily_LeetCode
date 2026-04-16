class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // Store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];

            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int prev = vec[(idx - 1 + vec.size()) % vec.size()];
            int next = vec[(idx + 1) % vec.size()];

            int d1 = abs(q - prev);
            int d2 = abs(q - next);

            int dist1 = min(d1, n - d1);
            int dist2 = min(d2, n - d2);

            ans.push_back(min(dist1, dist2));
        }

        return ans;
    }
};