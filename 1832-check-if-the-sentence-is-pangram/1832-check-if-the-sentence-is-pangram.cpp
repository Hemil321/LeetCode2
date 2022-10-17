class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.length();
        unordered_set<char> set;
        for(int i = 0; i < n; i++){
            set.insert(sentence[i]);
            if(set.size() == 26) return true;
        }
        return false;
    }
};