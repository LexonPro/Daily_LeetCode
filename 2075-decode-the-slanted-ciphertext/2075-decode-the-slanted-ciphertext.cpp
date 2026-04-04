#include <string>
#include <vector>

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) {
            return encodedText;
        }

        int n = encodedText.length();
        int cols = n / rows;
        string res = "";

        for (int start_col = 0; start_col < cols; ++start_col) {
            int r = 0;
            int c = start_col;

            while (r < rows && c < cols) {
                res += encodedText[r * cols + c];
                r++;
                c++;
            }
        }

        size_t last = res.find_last_not_of(' ');
        if (string::npos == last) {
            return "";
        }

        return res.substr(0, last + 1);
    }
};