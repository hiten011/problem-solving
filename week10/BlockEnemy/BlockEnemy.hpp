#include <bits/stdc++.h>
using namespace std;

class BlockEnemy {
    public:
        int minEffort(int N, vector<string> roads, vector<int> occupiedTowns) {
            n = N;
            adj = vector<vector<int>>(n, vector<int>(n, -1));
            for (string &s : roads) {
                s += " ";
                // cout << s << endl;
                vector<int> in;
                string t = "";
                for (char c : s) {
                    if (c == ' ') {
                        in.push_back(stoi(t));
                        t = "";
                        continue;
                    }

                    t += c;
                }

                adj[in[0]][in[1]] = in[2];
                adj[in[1]][in[0]] = in[2];
            }

            // for (auto i : adj) {
            //     for (auto j : i) {
            //         cout << j << " ";
            //     }

            //     cout << endl;
            // }

            enemy.clear();
            for (int i : occupiedTowns) {
                enemy.insert(i);
            }

            int ans = 0;
            for (int i : occupiedTowns) {
                vector<pair<int, int>> remove;
                dfs(i, remove);

                for (pair<int, int> r : remove) {
                    int u = r.first, v = r.second;

                    ans += adj[u][v];
                    adj[u][v] = -1;
                    adj[v][u] = -1;
                }
            }

            return ans;
        }

    private:
        int n;
        vector<vector<int>> adj;
        unordered_set<int> enemy;

        void dfs(int curNode, vector<pair<int, int>> &remove, int par = -1, int u = -1, int v = -1) {
            if (enemy.count(curNode) > 0 && par != -1) {
                // found a enemy
                remove.push_back({u, v});
                return;
            }

            for (int i = 0; i < n; i++) {
                if (i == par) continue;

                if (adj[curNode][i] != -1) {
                    int curu = u, curv = v;
                    if (u == -1 || adj[u][v] > adj[curNode][i]) {
                        curu = curNode;
                        curv = i;
                    }

                    dfs(i, remove, curNode, curu, curv);
                }
            }
        }
};