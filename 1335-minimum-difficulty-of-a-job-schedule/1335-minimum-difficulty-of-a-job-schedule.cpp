class Solution {
    int dp[301][11];
    int solve(vector<int>& j, int d, int idx, int n){
        if(idx == n){
            if(d != 0) return 1e7;
            else return 0;
        }
        if(d == 0) {
            return *max_element(begin(j) + idx, end(j));
        }
        if(dp[idx][d] != -1) return dp[idx][d];
        int currMax = INT_MIN, ans = 1e7;
        for(int i = idx; i < n; i++){
            currMax = max(currMax, j[i]);
            ans = min(ans, currMax + solve(j, d - 1, i + 1, n));
        }
        return dp[idx][d] = ans;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;
        memset(dp, -1, sizeof dp);
        return solve(jobDifficulty, d, 0, n);
    }
};