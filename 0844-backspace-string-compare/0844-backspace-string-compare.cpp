class Solution {
public:
    string process(string s) {
        string st;

        for (char c : s) {
            if (c == '#') {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(c);
            }
        }

        return st;
    }
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};