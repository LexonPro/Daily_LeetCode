class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
          int len = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for(int i = 0 ; i < len-2 ; i++){

            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = len-1;

            while( j < k){
                int sum = 0;
               
                sum = nums[i] + nums[j] + nums[k];
                 if(sum == target) return sum;

                if(abs(sum-target) < abs(closest - target)){
                    closest = sum;
                }
                 if(sum > target){
                    k--;
                }
                else if(sum < target){
                    j++;
                }
              
            }
        }
        return closest;
    }
};