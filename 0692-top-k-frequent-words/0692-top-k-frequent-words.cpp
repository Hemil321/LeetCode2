class Solution {
public:
    //First, store the words' frequencies in a map
    //Then, store all the frequencies into a priority queue with a comparator which will be defined like: sort them according to frequencies and if the frequencies are equal then according to the strings
    //And then insert the into the answer vector in a reverse order, as in the max heap word with the max frequency will be at the top and the answer is required in increasing order of the frequencies
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> map;
        int n = words.size();
        
        auto cmp = [](const pair<string,int>& a, const pair<string,int>& b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < n; i++) map[words[i]]++;
        
        for(auto j:map){
            pq.push({j.first, j.second});
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> ans;
        while(!pq.empty()){
            ans.insert(ans.begin(), pq.top().first);
            pq.pop();
        }
        return ans;
    }
};