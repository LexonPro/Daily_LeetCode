class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> temp;;
        for(int x:nums){
            if(temp.count(x)){
                return true;
            }
            temp.insert(x);
        }
       return false;
        }
        
    };
