const int mod = 1e9 + 7;
class Solution {
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n, int rem, int k, vector<vector<vector<int>>>& dp){
        if(i == m - 1 && j == n - 1) {
            return rem == 0;
        }
        if(dp[i][j][rem] != -1) return dp[i][j][rem];
        int right = 0, down = 0;
        if(j + 1 < n){
            right = solve(grid, i, j + 1, m, n, (rem + grid[i][j + 1]) % k, k, dp);
        }
        if(i + 1 < m){
            down = solve(grid, i + 1, j, m, n, (rem + grid[i + 1][j]) % k, k, dp);
        }
        return dp[i][j][rem] = (right + down) % mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        for(auto& j:grid){
            for(auto& i:j){
                i %= k;
            }
        }
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (k, -1)));
        return solve(grid, 0, 0, m, n, grid[0][0], k, dp);
    }
};