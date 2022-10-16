class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> distinct;
        for(auto& j:nums){
            distinct.insert(j);
            string curr = to_string(j);
            reverse(begin(curr), end(curr));
            distinct.insert(stoi(curr));
        }
        return distinct.size();
    }
};