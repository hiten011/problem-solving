#include <bits/stdc++.h>
using namespace std;

class HandsShaking
{
public:
    long long countPerfect(int n) {
        if (n % 2 == 1) return 0;

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 2; i <= n; i += 2) {
            for (int j = 0; j <= i - 2; j += 2) {
                dp[i] += dp[j] * dp[i - 2 - j];
            }
        }

        return dp[n];
        
    }

    private:
};
