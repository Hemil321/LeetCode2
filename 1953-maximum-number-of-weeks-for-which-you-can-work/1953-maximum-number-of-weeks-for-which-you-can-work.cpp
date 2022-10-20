class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long ans = 0;
        int maxEle = INT_MIN;
        for(auto& j:milestones){
            ans += j;
            maxEle = max(maxEle, j);
        }
        ans -= maxEle;
        if(ans >= maxEle){
            return ans + maxEle;
        }else{
            return (2 * ans) + 1;
        }
    }
};