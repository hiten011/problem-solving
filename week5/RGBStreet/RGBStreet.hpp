#include <bits/stdc++.h>
using namespace std;

class RGBStreet {
    public:
        int estimateCost(vector<string> houses) {
            int n = houses.size();
            vector<vector<int>> dp(n + 1, vector<int>(3, 0)); // [0: RED, 1: BLUE, 2: GREEN]
            dp[n][0] = 0; dp[n][1] = 0; dp[n][2] = 0;
            for (int i = n - 1; i >= 0; i--) {
                vector<int> color = getCost(houses[i] + " ");
                for (int c = 0; c < 3; c++) {
                    // choose color c
                    int minVal = min(dp[i + 1][(c + 1) % 3], dp[i + 1][(c + 2) % 3]);
                    dp[i][c] = minVal + color[c];
                }
            }

            return min(dp[0][0], min(dp[0][1], dp[0][2]));
        }

        vector<int> getCost(const string &house) {
            vector<int> ans(3, 0);
            int idx = 0, prev = 0;
            for (int i = 0; i < house.size(); i++) {
                if (house[i] == ' ') {
                    ans[idx++] = stoi(house.substr(prev, i - prev));
                    prev = i + 1;
                }
            }

            return ans;
        }
};