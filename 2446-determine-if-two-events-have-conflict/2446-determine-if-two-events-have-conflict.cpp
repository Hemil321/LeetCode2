class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int st1 = stoi(event1[0].substr(0, 2)) * 60 + stoi(event1[0].substr(3));
        int et1 = stoi(event1[1].substr(0, 2)) * 60 + stoi(event1[1].substr(3));
        int st2 = stoi(event2[0].substr(0, 2)) * 60 + stoi(event2[0].substr(3));
        int et2 = stoi(event2[1].substr(0, 2)) * 60 + stoi(event2[1].substr(3));
        unordered_set<int> time;
        for(int i = st1; i <= et1; i++){
            time.insert(i);
        }
        for(int i = st2; i <= et2; i++){
            if(time.count(i)) return true;
        }
        return false;
    }
};