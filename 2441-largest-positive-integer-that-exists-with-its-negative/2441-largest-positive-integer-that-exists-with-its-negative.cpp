class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> neg, pos;
        for(auto& j:nums){
            if(j < 0) neg.insert(j);
            else pos.insert(j);
        }
        int ans = -1;
        for(auto& j:pos){
            if(neg.count(-j)){
                ans = max(ans, j);
            }
        }
        return ans;
    }
};