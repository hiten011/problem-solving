#include <bits/stdc++.h>
using namespace std;

class TrafficMonitor {
    public:
        int getMin(vector<string> links) {
            n = links.size();
            adj = vector<vector<int>>(n, vector<int>());
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (links[i][j] == 'Y') {
                        adj[i].push_back(j);
                    }
                }
            }
            
            dp = vector<vector<int>>(2, vector<int>(n, -1));
            visited = vector<bool>(n, false);
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    ans += min(dfs(i, true), dfs(i, false));
                }
            }
            
            return ans;
        }

    private:
        int n;
        vector<vector<int>> adj;
        vector<vector<int>> dp;
        vector<bool> visited;

        int dfs(int curNode, bool putCamera, int par = -1) {
            if (dp[putCamera][curNode] != -1) return dp[putCamera][curNode];

            // mark as visited
            visited[curNode] = true;

            int ans = 0;
            for (int to : adj[curNode]) {
                if (to == par) continue;
                if (putCamera) {
                    ans += min(dfs(to, true, curNode), dfs(to, false, curNode));
                } else {
                    ans += dfs(to, true, curNode);
                }
            }

            // cout << curNode << ": " << ans << endl;
            return dp[putCamera][curNode] = ans + putCamera;
        }
};