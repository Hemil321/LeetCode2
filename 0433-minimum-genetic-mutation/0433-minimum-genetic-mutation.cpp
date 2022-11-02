class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size(), moves = 0;
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr == end) return moves;
                for(int i = 0; i < n; i++){
                    if(curr == bank[i]) continue;
                    int change = 0;
                    for(int j = 0; j < 8; j++){
                        if(curr[j] != bank[i][j]){
                            change++;
                        }
                    }
                    if(change == 1){
                        if(!visited.count(bank[i])){
                            visited.insert(bank[i]);
                            q.push(bank[i]);
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};