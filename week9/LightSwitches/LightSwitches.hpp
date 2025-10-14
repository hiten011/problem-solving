#include <bits/stdc++.h>
using namespace std;

class LightSwitches {
    public:
        long long countPossibleConfigurations(vector<string> switches) {
            // bipartite graphs
            // 1. create adj list
            int n = switches.size(), k = switches[0].size();
            for (int i = 0; i < n; i++) {
                // switch i
                vector<int> bulbs;
                for (int j = 0; j < k; j++) {
                    if (switches[i][j] == 'Y') {
                        bulbs.push_back(j);
                    }
                }

                g.push_back(bulbs);
            }
            
            mt.assign(k, -1);
            vector<bool> used1(n, false);
            for (int v = 0; v < n; ++v) {
                for (int to : g[v]) {
                    if (mt[to] == -1) {
                        mt[to] = v;
                        used1[v] = true;
                        break;
                    }
                }
            }
            
            for (int v = 0; v < n; ++v) {
                if (used1[v]) continue;
                used.assign(n, false);
                try_kuhn(v);
            }

            int maxmimMatching = 0;
            for (int i = 0; i < k; ++i) {
                if (mt[i] != -1) {
                    maxmimMatching++; 
                }
            }

            return n - maxmimMatching;
        }

    private:
        int n, k;
        vector<vector<int>> g;
        vector<int> mt;
        vector<bool> used;

        bool try_kuhn(int v) {
            if (used[v])
                return false;
            used[v] = true;
            for (int to : g[v]) {
                if (mt[to] == -1 || try_kuhn(mt[to])) {
                    mt[to] = v;
                    return true;
                }
            }
            return false;
        }

};