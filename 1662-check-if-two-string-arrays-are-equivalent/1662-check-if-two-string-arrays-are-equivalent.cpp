class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for(auto& j:word1) s1 += j;
        for(auto& j:word2) s2 += j;
        return s1 == s2;
    }
};