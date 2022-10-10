class Solution {
public:
    string fractionAddition(string s) {
        vector<int> deno, nums;
        int n = s.length(), i = 0;
        while(i < n){
            if(s[i] == '-'){
                i++;
                string num, curr;
                while(i < n && s[i] != '/'){
                    num.push_back(s[i++]);
                }
                nums.push_back(-stoi(num));
                i++;
                while(i < n && s[i] != '+' && s[i] != '-'){
                    curr.push_back(s[i++]);
                }
                deno.push_back(stoi(curr));
            }else if(s[i] == '+'){
                i++;
                string num, curr;
                while(i < n && s[i] != '/'){
                    num.push_back(s[i++]);
                }
                nums.push_back(stoi(num));
                i++;
                while(i < n && s[i] != '+' && s[i] != '-'){
                    curr.push_back(s[i++]);
                }
                deno.push_back(stoi(curr));
            }else{
                string num, curr;
                while(i < n && s[i] != '/'){
                    num.push_back(s[i++]);
                }
                nums.push_back(stoi(num));
                i++;
                while(i < n && s[i] != '+' && s[i] != '-'){
                    curr.push_back(s[i++]);
                }
                deno.push_back(stoi(curr));
            }
        }
        int lcm = deno[0], sum = 0;
        for(int i = 1; i < deno.size(); i++){
            lcm = (lcm * deno[i] / __gcd(lcm, deno[i]));
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] *= (lcm / deno[i]);
            sum += nums[i];
        }
        string ans;
        if(sum % lcm == 0) {
            ans = to_string(sum / lcm) + "/1";
        }else if(lcm % sum == 0){
            if(sum < 0){
                ans = "-1/" + to_string(abs(lcm / sum));
            }else{
                ans = "1/" + to_string(lcm / sum);
            }
        }else{
            unordered_set<int> factors;
            int curr = abs(sum);
            for(int i = 1; i * i <= curr; i++){
                if(curr % i == 0){
                    factors.insert(i);
                    if(curr / i != i){
                        factors.insert(curr / i);
                    }
                }
            }
            for(int i = 2; i * i <= lcm; i++){
                if(lcm % i == 0){
                    if(factors.count(i)){
                        while(curr % i == 0 && lcm % i == 0){
                            sum /= i;
                            curr /= i;
                            lcm /= i;
                        }
                    }
                    if(lcm / i != i){
                        if(factors.count(lcm / i)){
                            int fact = lcm / i;
                            if(fact == 1) continue;
                            while(curr % fact == 0 && lcm % fact == 0){
                                sum /= fact;
                                curr /= fact;
                                lcm /= fact;
                            }
                        }
                    }
                }
            }
            ans = to_string(sum) + "/" + to_string(lcm);
        }
        return ans;
    }
};