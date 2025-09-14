#include <bits/stdc++.h>
using namespace std;

class ForestGarbage {
    public:
        vector<int> bestWay(vector<string> forest) {
            int n = forest.size(), m = forest[0].size();

            pair<int, int> loc = {0, 0}, finalLoc = {-1, -1};
            vector<vector<bool>> isGarabageNeg(n, vector<bool>(m, false));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    if (forest[i][j] == 'S') {
                        loc = {i, j};
                        continue;
                    }

                    if (forest[i][j] == 'F' || forest[i][j] == 'g') {
                        finalLoc = {i, j};
                        continue;
                    }

                    for (vector<int> d : dir) {
                        int newi = i + d[0], newj = j + d[1];
                        if (!outBounds(newi, newj, n, m) && forest[newi][newj] == 'g') {
                            isGarabageNeg[i][j] = true;
                        }
                    }
                }
            }

            vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {INT_MAX, INT_MAX}));
            queue<pair<int, int>> q;

            q.push(loc);
            dp[loc.first][loc.second] = {0, 0};

            while (!q.empty()) {
                pair<int, int> p = q.front();
                int i = p.first;
                int j = p.second;

                pair<int, int> g = dp[i][j];
                int curG = g.first + (forest[i][j] == 'g' ? 1 : 0);
                int curNg = g.second + (isGarabageNeg[i][j] ? 1 : 0);

                q.pop();

                for (vector<int> d : dir) {
                    int newi = i + d[0], newj = j + d[1];

                    if (outBounds(newi, newj, n, m)) continue;

                    pair<int, int> t = dp[newi][newj];
                    int tempG = t.first;
                    int tempNg = t.second;

                    if (curG < tempG || (curG == tempG && curNg < tempNg)) {
                        dp[newi][newj] = {curG, curNg};
                        q.push({newi, newj});
                    } 
                }
            }

            pair<int, int> p = dp[finalLoc.first][finalLoc.second];
            vector<int> v = {p.first, p.second};
            return v;
        }

    private:
        bool outBounds(int i, int j, int n, int m) {
            if (i < 0 || i >= n || j < 0 || j >= m) return true;
            return false;
        }

        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
};
