class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        prefix_sum[0] = 0;
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(!prefix_sum.count(sum % k)){
                prefix_sum[sum % k] = i + 1;
            }else if(prefix_sum[sum % k] < i){
                return true;
            }
        }
        return false;
    }
};