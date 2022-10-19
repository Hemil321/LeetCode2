class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int zeros = 0, n = s.length(), i = 0, j = 0, ans1 = 0, ans2 = 0;
        while(j < n){
            if(s[j] == 'F'){
                zeros++;
                while(i < n && i <= j && zeros > k){
                    if(s[i] == 'F') zeros--;
                    i++;
                }
            }
            ans1 = max(ans1, j - i + 1);
            j++;
        }
        i = 0, j = 0;
        int ones = 0;
        while(j < n){
            if(s[j] == 'T'){
                ones++;
                while(i < n && i <= j && ones > k){
                    if(s[i] == 'T') ones--;
                    i++;
                }
            }
            ans2 = max(ans2, j - i + 1);
            j++;
        }
        return max(ans1, ans2);
    }
};