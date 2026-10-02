class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < len-2 ; i++){

            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = len-1;

            while( j < k){
                int sum = 0;
                sum = nums[i] + nums[j] + nums[k];
                 if(sum > 0){
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                
                else{
                 ans.push_back({nums[i] , nums[j] , nums[k]}); j++;k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;
                
                }
               
            }
        }
        return ans;
    }
};