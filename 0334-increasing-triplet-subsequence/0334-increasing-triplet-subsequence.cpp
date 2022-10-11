//We just try to find out the LIS of size 3, which can be done using binary search efficiently rather than standard DP approach

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            if(idx == lis.size()){
                lis.push_back(nums[i]);
            }else{
                lis[idx] = nums[i];
            }
            if(lis.size() == 3) return true;
        }
        return false;
    }
};