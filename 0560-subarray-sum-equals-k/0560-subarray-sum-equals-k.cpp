class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size()+1,0);
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            prefix[i+1] = nums[i] + prefix[i];
        }
        for(int j = 0; j < prefix.size();j++){
        for(int l= j+1; l< prefix.size();l++){
            if(prefix[l] - prefix[j] == k){
                count++;
            }
        }
        }
        return count;
    }
};