#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int L = n + m - 1;
        string word(L, 'a');
        vector<bool> fixed(L, false);

        // Step 1: Apply 'T' constraints — stamp str2 at every 'T' position
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    int idx = i + j;
                    if (fixed[idx] && word[idx] != str2[j]) {
                        return ""; // conflict between two 'T' windows
                    }
                    word[idx] = str2[j];
                    fixed[idx] = true;
                }
            }
        }

        // Step 2: For each 'F' position, ensure the window does NOT match str2
        // We scan left to right; for each 'F' window that currently matches,
        // find the rightmost unfixed position in that window and change it.
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                // Check if this window matches str2
                bool matches = true;
                for (int j = 0; j < m; ++j) {
                    if (word[i + j] != str2[j]) {
                        matches = false;
                        break;
                    }
                }
                if (matches) {
                    // Find the rightmost unfixed position and change it
                    bool changed = false;
                    for (int j = m - 1; j >= 0; --j) {
                        int idx = i + j;
                        if (!fixed[idx]) {
                            // Pick a character != str2[j]
                            word[idx] = (str2[j] != 'a') ? 'a' : 'b';
                            changed = true;
                            break;
                        }
                    }
                    if (!changed) return ""; // all positions fixed, can't break match
                }
            }
        }

        // Step 3: Final validation — verify all constraints are satisfied
        for (int i = 0; i < n; ++i) {
            bool isMatch = true;
            for (int j = 0; j < m; ++j) {
                if (word[i + j] != str2[j]) {
                    isMatch = false;
                    break;
                }
            }
            if (str1[i] == 'T' && !isMatch) return "";
            if (str1[i] == 'F' && isMatch) return "";
        }

        return word;
    }
};