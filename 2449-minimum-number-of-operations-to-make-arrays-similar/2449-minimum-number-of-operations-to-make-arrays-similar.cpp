class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(begin(nums), end(nums));
        sort(begin(target), end(target));
        vector<int> even1, even2, odd1, odd2;
        for(auto& j:nums){
            if(j & 1){
                odd1.push_back(j);
            }else{
                even1.push_back(j);
            }
        }
        for(auto& j:target){
            if(j & 1){
                odd2.push_back(j);
            }else{
                even2.push_back(j);
            }
        }
        long ops = 0;
        for(int i = 0; i < odd1.size(); i++){
            ops += (abs(odd1[i] - odd2[i]) / 2);
        }
        for(int i = 0; i < even1.size(); i++){
            ops += (abs(even1[i] - even2[i]) / 2);
        }
        return ops / 2;
    }
};