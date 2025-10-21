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


            return(int) (helper(M, edge) % MOD);
        }

    private:
        unordered_map<int, unordered_map<int, unordered_map<string, long long>>> memo;
        vector<int> numConnection;
        const int MOD = 1e9 + 7;

        long long helper(int M, vector<pair<int, int>> &edge, int idx = 0) {
            string mask = toString();
            if (memo.count(M) > 0 && memo[M].count(idx) > 0 && memo[M][idx].count(mask) > 0) return memo[M][idx][mask];
            if (M == 0) return isPos();
            if (idx == edge.size()) return 0;

            pair<int, int> p = edge[idx];
            int u = p.first;
            int v = p.second;

            long long ans = 0;
            for (int i = 0; i <= M; i++) {
                numConnection[u] += i;
                numConnection[v] += i;

                ans = (helper(M - i, edge, idx + 1) + ans) % MOD;

                numConnection[u] -= i;
                numConnection[v] -= i;
            }

            return memo[M][idx][mask] = ans;
        }

        string toString() {
            string str;
            for (int i : numConnection) {
                str += to_string(i) + "/";
            }

            return str;
        }

        bool isPos() {
            for (int i : numConnection) {
                if (i % 2 == 1) return false;
            }
            return true;
        }
};