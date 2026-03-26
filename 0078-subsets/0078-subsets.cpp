class Solution {
public:
    void allSubsets(vector<int> &arr, vector<int> &temp, int i, vector<vector<int>> &subset){
        if(i == arr.size()){
            subset.push_back(temp);
            return;
        }

        // Include element
        temp.push_back(arr[i]);
        allSubsets(arr, temp, i+1, subset);

        // Exclude element
        temp.pop_back();
        allSubsets(arr, temp, i+1, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> subset;

        allSubsets(nums, temp, 0, subset);

        return subset;
    }
};