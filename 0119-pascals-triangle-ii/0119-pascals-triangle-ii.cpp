class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        
        long long val = 1;
        row.push_back(val);

        for (int k = 1; k <= rowIndex; k++) {
            val = val * (rowIndex - k + 1) / k;
            row.push_back(val);
        }

        return row;
    }
};