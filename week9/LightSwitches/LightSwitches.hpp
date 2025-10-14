#include <bits/stdc++.h>
using namespace std;

class LightSwitches {
    public:
        long long countPossibleConfigurations(vector<string> switches) {
            // bipartite graphs
            // 1. create adj list
            n = switches.size(), k = switches[0].size();
            vector<unordered_set<int>> adjS(n), adjB(k);
            for (int i = 0; i < n; i++) {
                // switch i
                for (int j = 0; j < k; j++) {
                    if (switches[i][j] == 'Y') {
                        adjS[i].insert(j);
                        adjB[j].insert(i);
                        // cout << i << ": " << j << endl;
                    }
                }
            }
            
            int ans = 0;
            vector<bool> used(k, false);
            for (int i = 0; i < n; i++) {
                // get vertice with lowest number of edges
                int node = getSmallest(adjS); //  O(n)
                // cout << node << ": " << adjS[node].size() << endl;
                bool isUnique = false;
                for (int to : adjS[node]) {
                    if (!used[to]) {
                        used[to] = true;

                        // erase bulb from adj
                        for (int s : adjB[to]) {
                            if (s == node) continue;
                            adjS[s].erase(to);
                        }

                        isUnique = true;
                    }
                }

                adjS[node].clear();

                if (isUnique) ans++;
                // cout << node << endl;
            }

            return pow(2, ans);
        }

    private:
        int n, k;
        int getSmallest(vector<unordered_set<int>> &adjS) {
            int minV = -1;
            for (int i = 0; i < n; i++) {
                if (adjS[i].size() == 0) continue;
                if (minV == -1) {
                    minV = i;
                }

                if (adjS[minV].size() > adjS[i].size()) {
                    minV = i;
                }
            }
            
            return (minV == -1 ? 0 : minV);
        }

};