class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        // Step 1: group indices
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: process each group
        for(auto &it : mp) {
            vector<int>& idx = it.second;
            int m = idx.size();

            long long left = 0;
            long long right = 0;

            // initial right sum
            for(int x : idx) right += x;
            right -= (long long)m * idx[0];

            for(int i = 0; i < m; i++) {
                ans[idx[i]] = left + right;

                if(i + 1 < m) {
                    long long gap = idx[i+1] - idx[i];

                    left += gap * (i + 1);
                    right -= gap * (m - i - 1);
                }
            }
        }

        return ans;
    }
};