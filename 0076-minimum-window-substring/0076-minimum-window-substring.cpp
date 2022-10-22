class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length(), i = 0, j = 0;
        unordered_map<char, int> freqMap, reqMap;
        for(auto& j:t){
            freqMap[j]++;
        }
        reqMap = freqMap;
        string ans;
        vector<int> crucial(m);
        unordered_map<char, vector<int>> occ;
        while(j < m){
            if(freqMap.count(s[j])){
                crucial[j] = 1;
                occ[s[j]].push_back(j);
                if(reqMap.count(s[j])){
                    reqMap[s[j]]--;
                    if(reqMap[s[j]] == 0){
                        reqMap.erase(s[j]);
                    }
                }else{
                    crucial[occ[s[j]][0]] = 0;
                    occ[s[j]].erase(occ[s[j]].begin());
                    while(i <= j && crucial[i] == 0){
                        i++;
                    }
                }
            }
            if(reqMap.size() == 0){
                while(i <= j && crucial[i] == 0){
                    i++;
                }
                string curr = s.substr(i, j - i + 1);
                if(ans == "") 
                    ans = curr;
                else if(curr.length() < ans.length()){
                    ans = curr;
                }else if(curr.length() == ans.length()){
                    ans = min(ans, curr);
                }
            }
            j++;
        }
        return ans;
    }
};