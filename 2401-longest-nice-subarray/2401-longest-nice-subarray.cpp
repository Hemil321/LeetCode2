class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        vector<vector<int>> bits(n, vector<int> (32));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32; j++){
                if(nums[i] & (1 << j)){
                    bits[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            int mask = 0;
            bool flag = true;
            for(int j = i; j < min(i + 30, n); j++){
                int curr = nums[j];
                for(int k = 0; k < 32; k++){
                    if(curr & (1 << k)){
                        if(mask & (1 << k)){
                            flag = false;
                            break;
                        }else{
                            mask |= (1 << k);
                        }
                    }
                }
                if(!flag){
                    ans = max(ans, j - i);
                    break;
                }else{
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};