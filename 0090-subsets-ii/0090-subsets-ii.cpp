class Solution {
public:
    void allSubsets(vector<int> &arr, vector<int> &temp, int i, vector<vector<int>> &subset){
        // Always push current subset
        subset.push_back(temp);

        for(int j = i; j < arr.size(); j++){
            // Skip duplicates
            if(j > i && arr[j] == arr[j-1]) continue;

            temp.push_back(arr[j]);
            allSubsets(arr, temp, j+1, subset);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> subset;
        vector<int> temp;

        allSubsets(nums, temp, 0, subset);

        return subset;
    }
};