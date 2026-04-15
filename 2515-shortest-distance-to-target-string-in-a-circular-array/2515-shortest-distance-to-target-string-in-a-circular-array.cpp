class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int len = words.size();
        int minDistance = INT_MAX;

        for(int i = 0; i < len; i++){
            if(words[i] == target){
                int dist = abs(i - startIndex);
                int circularDist = min(dist, len - dist);
                minDistance = min(minDistance, circularDist);
            }
        }

        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};