class Solution {
public:
    // int singleNumber(vector<int>& nums){
    //     int ans = 0;
    //     for(auto j:nums) ans ^= j;
    //     return ans;
    // }
    
    int singleNumber(vector<int>& nums){
        sort(begin(nums), end(nums));
        int n = nums.size(), ans = nums[0];
        for(int i = 0; i < n; i++){
            if(i == n - 1) {
                ans = nums[i];
                break;
            }
            if(nums[i] != nums[i + 1]){
                ans = nums[i];
                break;
            }
            i++;
        }
        return ans;
    }
};