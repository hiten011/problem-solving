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

            isCamera = vector<bool>(n, false);
            for (int i = 0; i < n; i++) {
                isCamera[i] = true;
                bool isCameraTemp = false;
                for (int to : adj[i]) {
                    if (!isCamera[to]) {
                        isCameraTemp = true;
                    } else {
                        if (ifRemove(to)) {
                            isCameraTemp = true;
                            isCamera[to] = false;
                        }
                    }
                }

                if (!isCameraTemp) {
                    isCamera[i] = false;
                }
            }

            int ans = 0;
            for (bool i : isCamera) {
                if (i) ans++;
            }

            return ans;
        }

    private:
        int n;
        vector<vector<int>> adj;
        vector<bool> isCamera;

        bool ifRemove(int node) {
            for (int to : adj[node]) {
                if (!isCamera[to]) return false;
            }

            return true;
        }
};