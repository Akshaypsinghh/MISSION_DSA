class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + stoneValue[i];
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        function<int(int,int)> dfs = [&](int l, int r) {
            if (l == r) return 0;
            if (dp[l][r] != -1) return dp[l][r];
            int best = 0;
            for (int k = l; k < r; k++) {
                int left = prefix[k+1] - prefix[l];
                int right = prefix[r+1] - prefix[k+1];
                if (left < right) best = max(best, left + dfs(l, k));
                else if (left > right) best = max(best, right + dfs(k+1, r));
                else best = max(best, left + max(dfs(l, k), dfs(k+1, r)));
            }
            return dp[l][r] = best;
        };
        
        return dfs(0, n-1);
    }
};
