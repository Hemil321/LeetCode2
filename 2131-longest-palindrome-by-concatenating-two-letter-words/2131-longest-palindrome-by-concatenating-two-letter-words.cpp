class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freqMap;
        for(auto& j:words){
            freqMap[j]++;
        }
        int ans = 0, maxSame = 0;
        bool odd = false;
        for(auto& j:freqMap){
            if(j.first[0] == j.first[1]){
                if(j.second % 2 == 0){
                    ans += (j.second * 2);
                }else{
                    ans += ((j.second - 1) * 2);
                    odd = true;
                }
            }else{
                string rev;
                rev.push_back(j.first[1]);
                rev.push_back(j.first[0]);
                if(freqMap.count(rev)){
                    ans += (min(freqMap[rev], j.second) * 4);
                    freqMap.erase(rev);
                }
            }
        }
        if(odd) ans += 2;
        return ans;
    }
};