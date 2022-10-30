class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, tot = 0;
        for(auto& j:nums){
            if(j % 6 == 0){
                sum += j;
                tot++;
            }
        }
        return tot == 0 ? 0 : sum / tot;
    }
};