class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            int curr = nums[i];
            if(curr == k) ans++;
            for(int j = i + 1; j < n; j++){
                curr = __gcd(curr, nums[j]);
                if(curr == k) ans++;
            }
        }
        return ans;
    }
};