class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while(j < n){
            int row = i, col = j;
            unordered_set<int> eles;
            while(row < m && col < n){
                eles.insert(matrix[row][col]);
                row++; col++;
            }
            if(eles.size() > 1) return false;
            i--;
            if(i < 0){
                i = 0;
                j++;
            }
        }
        return true;
    }
};