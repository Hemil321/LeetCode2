#define ll long long
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<ll, ll>> curr;
        for(int i = 0; i < n; i++){
            curr.push_back({nums[i], cost[i]});
        }
        sort(begin(curr), end(curr));
        vector<ll> prefix(n);
        prefix[0] = curr[0].second;
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + curr[i].second;
        }
        ll currCost = 0, ans = LONG_MAX;
        for(int i = 0; i < n - 1; i++){
            currCost += curr[i].second * (abs(curr[n - 1].first - curr[i].first));   
        }
        ans = min(ans, currCost);
        for(int i = n - 2; i >= 0; i--){
            int diff = abs(curr[i].first - curr[i + 1].first);
            currCost = currCost - (prefix[i] * diff) + ((prefix[n - 1] - prefix[i]) * diff);
            ans = min(ans, currCost);
        }
        return ans;
    }
};