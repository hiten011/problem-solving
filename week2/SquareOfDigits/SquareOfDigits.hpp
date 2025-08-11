#include <bits/stdc++.h>
using namespace std;

class SquareOfDigits { 
    public:
        vector<vector<int>> dir = {{1, 0}, {1, 1}, {0, 1}};
        int getMax(vector<string> data) {
            int ans = 1;
            int n = data[0].size(), m = data.size();
            vector<vector<int>> dp(n, vector<int>(m, 1));

            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    int maxSquare = INT_MAX;
                    
                    for (auto &d : dir) {
                        if (data[i][j] == data[i + d[0]][j + d[1]]) maxSquare = min(dp[i + d[0]][j + d[1]], maxSquare);
                        else maxSquare = 0;
                    }

                    dp[i][j] = maxSquare + 1;
                    ans = max(dp[i][j], ans);
                }
            }

            return ans;
        };
};