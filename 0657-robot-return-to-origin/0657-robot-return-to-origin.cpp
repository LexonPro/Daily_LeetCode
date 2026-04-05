class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> m(4, 0); 

        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'U'){
                m[0]++;
            }
            else if(moves[i] == 'D'){
                m[1]++;
            }
            else if(moves[i] == 'L'){
                m[2]++;
            }
            else if(moves[i] == 'R'){
                m[3]++;
            }
        }

        if(m[0] == m[1] && m[2] == m[3]) return true;

        return false;
    }
};