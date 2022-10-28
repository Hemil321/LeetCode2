class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> ans;
        vector<string> groups;
        for(int i = 0; i < n; i++){
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            anagrams[strs[i]].push_back(temp);
        }
        for(auto j:anagrams){
            for(auto i:j.second){
                groups.push_back(i);
            }
            ans.push_back(groups);
            groups.clear();
        }
        return ans;
    }
};