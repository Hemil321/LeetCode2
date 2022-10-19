class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqMap;
        int n = s.length(), i = 0, j = 0, ans = 0;
        while(j < n){
            freqMap[s[j]]++;
            int tot = 0, maxF = INT_MIN;
            for(auto& j:freqMap){
                tot += j.second;
                maxF = max(maxF, j.second);
            }
            if(tot - maxF > k){
                freqMap[s[i]]--;
                if(freqMap[s[i]] == 0){
                    freqMap.erase(s[i]);
                }
                i++;
            }else{
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        return ans;
    }
};