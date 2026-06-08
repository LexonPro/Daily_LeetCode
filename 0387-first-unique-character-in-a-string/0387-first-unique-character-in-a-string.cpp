class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.size();

        for (int i = 0; i < len; i++) {
            bool unique = true;

            for (int j = 0; j < len; j++) {
                if (i != j && s[i] == s[j]) {
                    unique = false;
                    break;
                }
            }

            if (unique) return i;
        }

        return -1;
    }
};