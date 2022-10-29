class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> indices;
        int n = plantTime.size();
        for(int i = 0; i < n; i++){
            indices.push_back({growTime[i], plantTime[i]});
        }
        sort(begin(indices), end(indices), greater<pair<int, int>>());
        int ans = 0, currPlantTime = 0;
        for(auto& j:indices){
            currPlantTime += j.second;
            ans = max(ans, currPlantTime + j.first);
        }
        return ans;
    }
};