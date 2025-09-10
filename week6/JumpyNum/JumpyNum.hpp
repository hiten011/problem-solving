#include <bits/stdc++.h>
using namespace std;

class JumpyNum {
    public:
        int howMany(int low, int high) {
            vector<vector<long long>> dp(12, vector<long long>(11, 0));
            calc(dp);

            return (int)count(dp, to_string(high)) - count(dp, to_string(low - 1));
        }
    
    private:
        long long count(vector<vector<long long>> &dp, string h) {
            int n = h.size();
            if (h.size() == 1) return getInt(h[0]) + 1;

            vector<long long> highDp(n + 1);
            reverse(h.begin(), h.end());
            highDp[0] = 0;
            for (int i = 1; i < n; i++) {
                int idx = getInt(h[i]);

                for (int j = getInt(h[i - 1]); j >= 0; j--) {
                    if (j == idx + 1 || j == idx || j == idx - 1) continue;

                    if (i != 1 && getInt(h[i - 1]) == j) highDp[i] += highDp[i - 1];
                    else highDp[i] += dp[i - 1][j];
                }
            }

            highDp[n] = highDp[n - 1];
            for (int i = getInt(h[n - 1]) - 1; i >= 0; i--) {
                if (i == 0) highDp[n] += dp[n - 1][10];
                else highDp[n] += dp[n - 1][i];
            }

            // cout << highDp[n] << endl;

            return highDp[n];
        }

        void calc(vector<vector<long long>> &vec) {
            for (int i = 0; i < 11; i++) {
                vec[0][i] = 1;
            }

            for (int i = 1; i < vec.size(); i++) {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 10; k++) {
                        if (k == j - 1 || k == j + 1 || k == j) continue;
                        vec[i][j] += vec[i - 1][k];
                    }
                }

                for (int j = 0; j < 10; j++) {
                    vec[i][10] += vec[i - 1][j];
                }
            }

        }

        int getInt(char c) {return (int)(c - '0');}
};