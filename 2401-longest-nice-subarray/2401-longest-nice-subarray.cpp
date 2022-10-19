class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1, i = 0, j = 0, mask = 0;
        vector<int> bits(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32; j++){
                if(nums[i] & (1 << j)){
                    bits[i] |= (1 << j);
                }
            }
        }
        while(j < n){
            while(i < n && (mask & bits[j]) >= 1){
                mask ^= bits[i];
                i++;
            }
            mask |= bits[j];
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};