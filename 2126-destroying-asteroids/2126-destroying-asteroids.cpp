class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curr = mass;

        sort(asteroids.begin(), asteroids.end());

        for (int a : asteroids) {
            if (curr < a) {
                return false;
            }
            curr += a;
        }

        return true;
    }
};