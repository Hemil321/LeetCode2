//Make a pair for every character that are same and keep increasing their frequency 
//If at some point the characters are no longer same then insert the frequency and the number into answer string and then assign a new pair with that character as the key
//And then return the answer

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        string ans;
        pair<char,int> freqPair = {0,0};
        while(--n){
            int len = s.length();
            char currChar = s[0];
            freqPair = {currChar, 1};
            for(int i = 1; i < len; i++){
                if(s[i] != freqPair.first){
                    ans += freqPair.second + '0';
                    ans += freqPair.first;
                    freqPair = {s[i], 1};
                }else{
                    freqPair.second++;
                }
            }
            ans += freqPair.second + '0';
            ans += freqPair.first;
            s = ans;
            ans.clear();
        }
        return s;
    }
};