class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int len = nums.size();
        int minimum = INT_MAX;
        for(int i = 0 ; i < len ; i++){
            if(nums[i] == target){
                minimum = min(abs(i-start),minimum);
            }
        }
        return minimum;
    }
};