class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        
        // flatten grid
        for(auto &row : grid) {
            for(auto &val : row) {
                nums.push_back(val);
            }
        }
        
        // check feasibility
        int rem = nums[0] % x;
        for(int num : nums) {
            if(num % x != rem) return -1;
        }
        
        // sort
        sort(nums.begin(), nums.end());
        
        // median
        int mid = nums[nums.size()/2];
        
        // calculate operations
        int ops = 0;
        for(int num : nums) {
            ops += abs(num - mid) / x;
        }
        
        return ops;
    }
};