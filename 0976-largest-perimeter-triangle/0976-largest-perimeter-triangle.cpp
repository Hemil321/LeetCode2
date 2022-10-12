class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(rbegin(nums), rend(nums));
        for(int i = 0; i <= n - 3; i++){
            double s = 1.0 * (nums[i] + nums[i + 1] + nums[i + 2]) / 2;
            if(s - nums[i] > 0 && s - nums[i + 1] > 0 && s - nums[i + 2] > 0){
                ans = max(ans, (int)(s * 2));
            }
        }
        return ans;
    }
};