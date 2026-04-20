class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        vector<int> temp;

        for(int i = 0; i < len; i++) {
            int maxRight = -1;

            for(int j = i + 1; j < len; j++) {
                maxRight = max(maxRight, arr[j]);
            }

            temp.push_back(maxRight);
        }

        return temp;
    }
};