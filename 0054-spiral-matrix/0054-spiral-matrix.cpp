class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> temp;

        int top = 0;
        int bottom = row - 1;
        int left = 0;
        int right = col - 1;

        while (top <= bottom && left <= right) {

            
            for (int i = left; i <= right; i++) {
                temp.push_back(matrix[top][i]);
            }
            top++;

        
            for (int i = top; i <= bottom; i++) {
                temp.push_back(matrix[i][right]);
            }
            right--;


            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    temp.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

        
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    temp.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return temp;
    }
};