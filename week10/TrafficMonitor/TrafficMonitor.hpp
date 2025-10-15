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
                        adj[j].push_back(i);
                    }
                }
            }
            
            dp = vector<vector<int>>(2, vector<int>(n, -1));
            int ans = 0;
            for (int i = 0; i < 1; i++) {
                ans = min(dfs(i, true), dfs(i, false));
            }

            return ans;
        }

    private:
        int n;
        vector<vector<int>> adj;
        vector<vector<int>> dp;

        int dfs(int curNode, bool putCamera, int par = -1) {
            int ans = 0;

            for (int to : adj[curNode]) {
                if (to == par) continue;
                if (putCamera) {
                    ans += min(dfs(to, true, curNode), dfs(to, false, curNode));
                } else {
                    ans += dfs(to, true, curNode);
                }
            }

            return ans + putCamera;
        }
};