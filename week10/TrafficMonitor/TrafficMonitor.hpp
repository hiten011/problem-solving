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
            
            color = vector<int>(n, -1);
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (color[i] == -1) {
                    pair<int, int> p = bfs(i);
                    ans += min(p.first, p.second);
                }
            }

            return ans;
        }

    private:
        int n;
        vector<vector<int>> adj;
        vector<int> color;

        pair<int, int> bfs(int node) {
            int red = 1, blue = 0;
            color[node] = 1;

            queue<int> q;
            q.push(node);
            while (!q.empty()) {
                int curNode = q.front();
                q.pop();

                for (int to : adj[curNode]) {
                    if (color[to] == -1) {
                        color[to] = (color[curNode] + 1) % 2;
                        q.push(to);

                        if (color[to] == 0) {
                            blue++;
                        } else {
                            red++;
                        }
                    }
                }
            }

            return {blue, red};
        }
};