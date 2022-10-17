class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.length();
        if(pattern[0] == pattern[1]){
            int total = 1;
            for(auto& j:text){
                if(j == pattern[0]){
                    total++;
                }
            }
            long ans = (1ll * total * (total - 1) / 2);
            return ans;
        }else{
            vector<int> pref1(n), pref2(n);
            unordered_set<int> ch;
            if(text[0] == pattern[0]){
                pref1[0]++;
            }else if(text[0] == pattern[1]){
                ch.insert(0);
                pref2[0]++;
            }
            for(int i = 1; i < n; i++){
                if(text[i] == pattern[0]){
                    pref1[i] = pref1[i - 1] + 1;
                    pref2[i] = pref2[i - 1]; 
                }else if(text[i] == pattern[1]){
                    ch.insert(i);
                    pref2[i] = pref2[i - 1] + 1;
                    pref1[i] = pref1[i - 1];
                }else{
                    pref1[i] = pref1[i - 1];
                    pref2[i] = pref2[i - 1];
                }
            }
            // for(auto& j:pref1){
            //     cout << j << ' ';
            // }
            // cout << '\n';
            // for(auto& j:pref2){
            //     cout << j << ' ';
            // }
            // cout << '\n';
            long long curr = 0;
            for(auto& j:ch){
                curr += pref1[j];
            }
            curr += max(pref1[n - 1], pref2[n - 1]);
            return curr;
        }
    }
};