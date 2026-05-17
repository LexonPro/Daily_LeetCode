class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(start);
        vis[start] = true;

        while(!q.empty()) {
            int idx = q.front();
            q.pop();

            if(arr[idx] == 0) return true;

            int left = idx - arr[idx];
            int right = idx + arr[idx];

            if(left >= 0 && !vis[left]) {
                vis[left] = true;
                q.push(left);
            }

            if(right < n && !vis[right]) {
                vis[right] = true;
                q.push(right);
            }
        }

        return false;
    }
};