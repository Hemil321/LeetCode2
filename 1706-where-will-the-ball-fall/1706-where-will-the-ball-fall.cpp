class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int row = 0, col = i;
            while(row < m){
                if(grid[row][col] == -1){
                    if(col - 1 < 0){
                        ans[i] = -1;
                        break;
                    }else if(grid[row][col - 1] == 1){
                        ans[i] = -1;
                        break;
                    }else{
                        row++; col--;
                    }
                }else{
                    if(col + 1 == n){
                        ans[i] = -1;
                        break;
                    }else if(grid[row][col + 1] == -1){
                        ans[i] = -1;
                        break;
                    }else{
                        row++; col++;
                    }
                }
            }
            if(ans[i] != -1) ans[i] = col;
        }
        return ans;
    }
};