#define pii pair<int, int>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n++;
        auto compare = [](pii& a, pii& b) {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        };
        priority_queue<pii, vector<pii>, decltype(compare)> pq(compare);
        unordered_map<char, int> freqMap;
        for(auto& j:tasks){
            freqMap[j]++;
        }
        for(auto& j:freqMap){
            pq.push({0, j.second});
        }
        int time = 0;
        while(!pq.empty()){
            int curr = pq.top().first;
            int freq = pq.top().second;
            pq.pop();
            if(curr <= time){
                freq--;
                if(freq != 0){
                    pq.push({curr + n, freq});
                }
            }else{
                time = curr;
                freq--;
                if(freq != 0){
                    pq.push({time + n, freq});
                }
            }
            time++;
        }
        return time;
    }
};