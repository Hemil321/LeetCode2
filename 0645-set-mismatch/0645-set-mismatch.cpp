class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k = -1, j = -1;
        for(int i = 0; i < nums.size() - 1; i++){
            //If we have found the repeating and missing then no need to iterate further
            if(j != -1 && k != -1) break;
            if(nums[i] == nums[i + 1]) {
                //If the missing element is the last element then we also need to check for that edge case
                nums.erase(nums.begin() + i);
                k = nums[i];
                nums.emplace_back(0);
            }
            //If the missing element comes before the repeating element then every element will be on their one index left, so if a missing number is found then no need to check the condition again
            if(nums[i] != i + 1 && j == -1) j = i + 1; 
        }
        if(j == -1) j = nums.size();
        return {k, j};
    }
};