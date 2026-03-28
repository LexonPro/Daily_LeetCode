class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        // Step 1: Check diagonal
        for(int i = 0; i < n; i++){
            if(lcp[i][i] != n - i) return "";
        }

        // DSU
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        function<int(int)> find = [&](int x){
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b){
            parent[find(a)] = find(b);
        };

        // Step 2: Union where lcp[i][j] > 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(lcp[i][j] > 0){
                    unite(i, j);
                }
            }
        }

        // Step 3: Assign characters
        unordered_map<int, char> mp;
        char ch = 'a';

        string word(n, '?');

        for(int i = 0; i < n; i++){
            int p = find(i);
            if(mp.find(p) == mp.end()){
                if(ch > 'z') return "";
                mp[p] = ch++;
            }
            word[i] = mp[p];
        }

        // Step 4: Validate LCP
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(word[i] == word[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
            }
        }

        // Compare
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] != lcp[i][j]) return "";
            }
        }

        return word;
    }
};