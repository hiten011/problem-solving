#include <bits/stdc++.h>
using namespace std;

class JumpyNum {
    public:
        int howMany(int low, int high) {
            if (low < 1) low = 1;
            return count(to_string(high)) - count(to_string(low - 1));
        }
    
    private:

        int count(string num) {
            int n = num.size();
            if (n == 1) return getInt(num[0]) + 1;

            vector<vector<int>> dp(n, vector<int>(11, 0));
            for (int i = 0; i < 10; i++) {
                dp[n - 1][i] = 1;
            }

            for (int i = n - 2; i >= 0; i--) {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 10; k++) {
                        if (k == j || k == j + 1 || k == j - 1) continue;
                        dp[i][j] += dp[i + 1][k];
                    }
                }

                for (int j = 0; j < 11; j++) {
                    dp[i][10] += dp[i + 1][j];
                }
            }

            int ans = 1;
            for (int i = n - 2; i >= 0; i--) {
                int h = getInt(num[i]), sum = 0;
                for (int j = 0; j <= getInt(num[i + 1]); j++) {
                    if (h == j + 1 || h == j || h == j - 1) continue;

                    if (j == getInt(num[i + 1])) sum += ans;
                    else sum += dp[i + 1][j];
                }

                ans = sum;
            }

            for (int i = 1; i < getInt(num[0]); i++) {
                ans += dp[0][i];
            }
            ans += dp[0][10];
            return ans;
        }

        int getInt(char c) {return (int)(c - '0');}
};