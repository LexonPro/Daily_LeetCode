class Solution {
public:
    vector<int> ans;

    void digit(int num) {
        vector<int> temp;

        while (num > 0) {
            int r = num % 10;
            temp.push_back(r);
            num /= 10;
        }

        reverse(temp.begin(), temp.end());

        for (int x : temp) {
            ans.push_back(x);
        }
    }

    vector<int> separateDigits(vector<int>& nums) {
        for (int num : nums) {
            digit(num);
        }

        return ans;
    }
};