class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        int len = s.size();

        for(int i = 0; i < len; i++) {
            if(s[i] == ' ') {
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            }
        }

        reverse(s.begin() + j, s.end());

        return s;
    }
};