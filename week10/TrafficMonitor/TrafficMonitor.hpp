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

            isCamera = vector<int>(n, 0);
            for (int i = 0; i < n; i++) {
                if (dfs(i)) {
                    isCamera[i] = true;
                }
            }

            int ans = 0;
            for (int i : isCamera) {
                if (i == 2) ans++;
            }

            return ans;
        }

    private:
        int n;
        vector<vector<int>> adj;
        vector<int> isCamera;

        bool dfs(int node) {
            isCamera[node] = 3;

            bool isPos = true;
            for (int to : adj[node]) {
                if (isCamera[to] == 3) continue;
                if (isCamera[to] == 0) {
                    isPos = false;
                    continue;
                }

                if (dfs(to)) {
                    isCamera[to] = 0;
                    isPos = false;
                }
            }

            isCamera[node] = 2;
            return isPos;
        }
};