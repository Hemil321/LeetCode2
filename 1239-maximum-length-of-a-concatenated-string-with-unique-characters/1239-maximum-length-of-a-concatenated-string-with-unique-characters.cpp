class Solution {
    int ans = INT_MIN;
    void solve(vector<string>& arr, int mask, int idx){
        int currCount = 0, n = arr.size();
        for(int i = 0; i < 26; i++){
            if(mask & (1 << i)){
                currCount++;
            }
        }
        ans = max(ans, currCount);
        for(int i = idx; i < n; i++){
            string s = arr[i];
            int len = s.length();
            bool flag = true, same = false;
            sort(begin(s), end(s));
            for(int k = 0; k < len - 1; k++){
                if(s[k] == s[k + 1]){
                    same = true;
                    break;
                }
            }
            if(same) continue;
            for(int j = 0; j < len; j++){
                if(mask & (1 << (s[j] - 'a'))){
                    flag = false;
                    break;
                }
            }
            if(flag){
                for(int j = 0; j < len; j++){
                    mask |= (1 << (s[j] - 'a'));
                }
                solve(arr, mask, i + 1);
                for(int j = 0; j < len; j++){
                    mask ^= (1 << (s[j] - 'a'));
                }
            }
            
        }
    } 
public:
    int maxLength(vector<string>& arr) {
        solve(arr, 0, 0);
        return ans;
    }
};