#include <bits/stdc++.h>
using namespace std;

class UnsealTheSafe {
public:
    long countPasswords(int N) {
        vector<vector<long>> dp(N, vector<long>(10, 0));
        for (int i = 0; i < 10; i++) {
            dp[N - 1][i] = 1;
        } 

        for (int i = N - 2; i >= 0; i--) {
            for (int j = 0; j < 10; j++) {
                long cur = 0;
                for (int k : adj[j]) {
                    cur += dp[i + 1][k];
                }

                dp[i][j] = cur;
            }
        }

        long ans = 0;
        for (int i = 0; i < 10; i++) {
            ans += dp[0][i];
        }

        return ans;
    }

private:
    vector<vector<int>> adj = {
        /* 0 */ {7},
        /* 1 */ {2, 4},
        /* 2 */ {1, 3, 5},
        /* 3 */ {2, 6},
        /* 4 */ {1, 5, 7},
        /* 5 */ {2, 4, 6, 8},
        /* 6 */ {3, 5, 9},
        /* 7 */ {4, 8, 0},
        /* 8 */ {5, 7, 9},
        /* 9 */ {6, 8}};
};