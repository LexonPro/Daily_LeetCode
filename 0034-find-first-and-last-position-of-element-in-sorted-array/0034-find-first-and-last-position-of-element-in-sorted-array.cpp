class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int first = -1;
        int last = -1;
        
        for(int i = 0 ; i < len ; i++){
            if(nums[i] == target){
                first = i;
                break;
            } 
        }
        for(int j = len -1; j >= 0; j--){
            if(nums[j] == target){
                last = j;
                break;
            } 
        }
        return {first,last};
    }
};