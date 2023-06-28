//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool solve(int n, int k, int dist, vector<int>& stalls){
        bool possible = 0;
        int prev = stalls[0];
        for(int i = 1; i < n; i++){
            if(k == 0) break;
            if((stalls[i] - prev) >= dist){
                prev = stalls[i];
                k--;
            }
        }
        return k == 0;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(begin(stalls), end(stalls));
        int low = 0, high = stalls[n - 1], ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(solve(n, k - 1, mid, stalls)){
                low = mid + 1;
                ans = mid;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends