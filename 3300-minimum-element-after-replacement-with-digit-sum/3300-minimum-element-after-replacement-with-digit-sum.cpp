class Solution {
public:
    int digitsum(int num){
        int rem = 0;
        int sum = 0;
        while(num > 0){
            rem = num % 10;
            num/=10;
            sum += rem;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0 ; i < len ; i++){
            nums[i] = digitsum(nums[i]);
        }
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};