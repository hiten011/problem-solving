#include <bits/stdc++.h>
using namespace std;

class JumpyNum {
    public:
        int howMany(int low, int high) {
            return count(to_string(high)) - count(to_string(low - 1));
        }
    
    private:

        int count(string num) {
            int n = num.size();
            vector<vector<int>> dp(n, vector<int>(10, 0));

            for (int i = 0; i < 10; i++) {
                dp[n - 1][i] = 1;
            }

            int ans = 1;
            for (int i = n - 2; i >= 0; i--) {
                for (int j = 0; j < 10; j++) {
                    for (int k = 0; k < 10; k++) {
                        if (k == j || k == j + 1 || k == j - 1) continue;

                        dp[i][j] += dp[i + 1][k];
                    }
                }

                int h = getInt(num[i]);
                int sum = 0;
                for (int j = 0; j <= getInt(num[i + 1]); j++) {
                    if (h == j || h == j + 1 || h == j - 1) continue;

                    if (j == getInt(num[i + 1])) sum += ans;
                    else sum += dp[i + 1][j];
                }

                ans = sum;
            }

            for (int i = 1; i < getInt(num[0]); i++) {
                ans += dp[0][i];
            }

            return ans;
        }

        // // long long count(vector<vector<long long>> &dp, string num) {
        // //     int n = num.size();

        // //     vector<long long> hDp(n, 0);
        // //     for (int i = n - 2; i >= 0; i--) {
        // //         int h = getInt(num[i]);

        // //         for (int j = 0; j <= getInt(num[i - 1]); j++) {
        // //             if (h == j + 1 || h == j || h == j - 1) continue;

        // //             if (j == getInt(num[i - 1])) hDp[i] += hDp[i - 1];
        // //             else hDp[i] += dp[i - 1][j];
        // //         }
        // //     }

        // //     long long sum = hDp[0];
        // //     for (int i = 0; i < getInt(num[0]); i++) {
        // //         sum += dp[]
        // //     }
        // // }

        // // void pad(string &l, string &h) {
        // //     int diff = h.size() - l.size();
        // //     l.append('0', diff);
        // // }

        // long long count(vector<vector<long long>> &dp, string h) {
        //     int n = h.size();
        //     if (h.size() == 1) return getInt(h[0]) + 1;

        //     vector<long long> highDp(n, 0);
        //     reverse(h.begin(), h.end());
        //     for (int i = 1; i < n; i++) {
        //         int idx = getInt(h[i]);

        //         for(int j = 0; j <= getInt(num[i - 1]); j++) {
        //             //             if (h == j + 1 || h == j || h == j - 1) continue;

        //             //             if (j == getInt(num[i - 1])) hDp[i] += hDp[i - 1];
        //             //             else hDp[i] += dp[i - 1][j];
        //             //         }
        //         }

        //     highDp[n] = highDp[n - 1];
        //     for (int i = getInt(h[n - 1]) - 1; i >= 0; i--) {
        //         if (i == 0) highDp[n] += dp[n - 1][10];
        //         else highDp[n] += dp[n - 1][i];
        //     }

        //     // cout << highDp[n] << endl;

        //     return highDp[n];
        // }

        // void calc(vector<vector<long long>> &vec) {
        //     for (int i = 0; i < 10; i++) {
        //         vec[0][i] = 1;
        //     }

        //     for (int i = 1; i < vec.size(); i++) {
        //         for (int j = 0; j < 10; j++) {
        //             for (int k = 0; k < 10; k++) {
        //                 if (k == j - 1 || k == j + 1 || k == j) continue;
        //                 vec[i][j] += vec[i - 1][k];
        //             }
        //         }
        //     }

        // }

        int getInt(char c) {return (int)(c - '0');}
};