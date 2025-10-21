#include <bits/stdc++.h>
using namespace std;

class DengklekBuildingRoads {
    public:
        int numWays(int N, int M, int K) {
            numConnection = vector<int>(N, 0);
            vector<pair<int, int>> edge;
            for (int i = 0; i < N; i++) {
                for (int j = 1; j <= K && i + j < N; j++) {
                    edge.push_back({i, j + i});
                }
            }


            return helper(M, edge);
        }

    private:
        unordered_map<int, unordered_map<int, int>> memo;
        vector<int> numConnection;
        const int MOD = 1e9 + 7;

        long long helper(int M, vector<pair<int, int>> edge, int idx = 0) {
            if (M == 0) return isPos();
            if (idx == edge.size()) return 0;

            pair<int, int> p = edge[idx];
            int u = p.first;
            int v = p.second;

            long long ans = 0;
            for (int i = 0; i <= M; i++) {
                numConnection[u] += i;
                numConnection[v] += i;

                ans += helper(M - i, edge, idx + 1);

                numConnection[u] -= i;
                numConnection[v] -= i;
            }

            return ans;
        }

        bool isPos() {
            for (int i : numConnection) {
                if (i % 2 == 1) return false;
            }
            return true;
        }
};