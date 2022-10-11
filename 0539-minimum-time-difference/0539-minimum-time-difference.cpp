class Solution {
    int getMins(string& s){
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> mins;
        for(int i = 0; i < n; i++){
            int curr = getMins(timePoints[i]);
            mins.push_back(curr);
            mins.push_back(curr + 1440);
        }
        sort(begin(mins), end(mins));
        int ans = INT_MAX;
        for(int i = 1; i < mins.size(); i++){
            ans = min(ans, mins[i] - mins[i - 1]);
        }
        return ans;
    }
};