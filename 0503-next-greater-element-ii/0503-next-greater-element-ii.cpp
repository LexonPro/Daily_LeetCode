class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,-1);
        
        for(int i = 0 ; i < n;i++){

            for(int k = 1; k < n; k++){
                int j = (i+k) % n;
                if(nums[i] < nums[j]){

                    arr[i] = nums[j];
                    break;
                }
            }
        
        }
        return arr;
    }
};