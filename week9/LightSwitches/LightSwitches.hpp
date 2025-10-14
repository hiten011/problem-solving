#include <bits/stdc++.h>
using namespace std;

class LightSwitches {
    public:
        long long countPossibleConfigurations(vector<string> switches) {
            // bipartite graphs
            // 1. create adj list
            vector<vector<int>> adj;
            int n = switches.size(), k = switches[0].size();
            for (int i = 0; i < n; i++) {
                // switch i
                vector<int> bulbs;
                for (int j = 0; j < k; j++) {
                    if (switches[i][j] == 'Y') {
                        bulbs.push_back(j);
                    }
                }

                adj.push_back(bulbs);
            }

            sort(adj.begin(), adj.end(), [](vector<int> &a, vector<int> &b){
                return a.size() < b.size();
            });
            
            int ans = 0;
            vector<bool> used(k, false);
            for (int i = 0; i < n; i++) {
                bool isUnique = false;
                for (int to : adj[i]) {
                    if (!used[to]) {
                        isUnique = true;
                        used[to] = true;
                    }
                }

                if (isUnique) ans++;
            }

            return pow(2, ans);
        }

    private:
        int n, k;

};