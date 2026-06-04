class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
       int len = mat[0].size()-1;
       int dsum = 0;
       for(int i = 0; i <= len ; i++){
        for(int j = 0; j <= len ; j++){
            if(i == j || i+j == len){
                dsum += mat[i][j];
            }
            
        }
       
       }
    
       return dsum; 
    }
};