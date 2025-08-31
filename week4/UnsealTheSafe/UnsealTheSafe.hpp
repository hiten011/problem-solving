#include <bits/stdc++.h>
using namespace std;

class UnsealTheSafe {
public:
    long countPasswords(int N, int num = 10) {
        if (N == 0) return 1;
        
        if (memo.count(N) > 0 && memo[N].count(num) > 0) return memo[N][num];
        
        long ans = 0;
        for (int i : adj[num]) {
            ans += countPasswords(N - 1, i);
        }

        return memo[N][num] = ans;
    }

private:
    unordered_map<int, unordered_map<int, long>> memo;
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
        /* 9 */ {6, 8},
        /* 10 */ {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}};
};