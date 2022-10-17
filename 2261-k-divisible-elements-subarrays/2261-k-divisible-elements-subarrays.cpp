class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> distinct;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int curr = 0;
            vector<int> sub;
            for(int j = i; j < n; j++){
                if(nums[j] % p == 0){
                    curr++;
                }
                if(curr > k) break;
                sub.push_back(nums[j]);
                distinct.insert(sub);
            }
        }
        return distinct.size();
    }
};