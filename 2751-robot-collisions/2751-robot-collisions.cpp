#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        // Sort indices based on their positions
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });

        stack<int> st; // Stores indices of robots moving Right 'R'
        vector<bool> destroyed(n, false);

        for (int i : indices) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                // Robot is moving Left 'L', check for collisions with 'R' robots in stack
                while (!st.empty() && healths[i] > 0) {
                    int topIdx = st.top();
                    
                    if (healths[i] > healths[topIdx]) {
                        // Left robot wins
                        healths[i] -= 1;
                        healths[topIdx] = 0;
                        destroyed[topIdx] = true;
                        st.pop();
                    } else if (healths[i] < healths[topIdx]) {
                        // Right robot wins
                        healths[topIdx] -= 1;
                        healths[i] = 0;
                        destroyed[i] = true;
                        break; 
                    } else {
                        // Both destroyed
                        healths[i] = 0;
                        healths[topIdx] = 0;
                        destroyed[i] = true;
                        destroyed[topIdx] = true;
                        st.pop();
                        break;
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!destroyed[i]) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};