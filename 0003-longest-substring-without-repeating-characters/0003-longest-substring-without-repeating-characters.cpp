class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128,0);
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right < s.size()){
            freq[s[right]]++;
            
            while((freq[s[right]]) > 1){
                freq[s[left]]--;
                left++;
            }
            ans = max(ans,right - left + 1);
            right++;
        }
        return ans;
    }
};