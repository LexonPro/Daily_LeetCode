class Solution {
public:
    int maxDistance(vector<int>& colors) {
       int len = colors.size();
       int maxi = 0;
       for(int i = 0; i < len ; i++){
        for(int j = 0 ; j < len ; j++){
            if(i == j) continue;
            else if(colors[i] != colors[j]){
                maxi = max(abs(i-j),maxi);
            }
        }
       }
       return maxi; 
    }
};