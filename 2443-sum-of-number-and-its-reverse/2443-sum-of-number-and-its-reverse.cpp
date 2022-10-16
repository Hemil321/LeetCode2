class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++){
            int curr = i, sum = 0;
            while(curr){
                sum = (sum * 10) + (curr % 10);
                curr /= 10;
            }
            if(sum + i == num) return true;
        }
        return false;
    }
};