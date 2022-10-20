class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;      
        unordered_map<char, int> freqMap;
        for(auto& j:s){
            freqMap[j]++;
        }
        for(auto& j:freqMap){
            pq.push({j.second, j.first});
        }
        string ans;
        while(!pq.empty()){
            int freq1 = pq.top().first;
            char curr1 = pq.top().second;
            pq.pop();
            if(pq.empty()) {
                if(freq1 == 1) {
                    ans.push_back(curr1);
                    break;
                }
                else return "";
            }
            int freq2 = pq.top().first;
            char curr2 = pq.top().second;
            pq.pop();
            ans.push_back(curr1);
            ans.push_back(curr2);
            freq1--;
            freq2--;
            if(freq1 != 0){
                pq.push({freq1, curr1});
            }
            if(freq2 != 0){
                pq.push({freq2, curr2});
            }
        }
        return ans;
    }
};