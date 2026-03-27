class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // We only care about k % n because shifting by n 
        // positions returns the row to its original state.
        k = k % n;
        if (k == 0) return true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the element at j is not equal to the element 
                // k positions away (cyclically), the matrix changes.
                if (mat[i][j] != mat[i][(j + k) % n]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};