#include <bits/stdc++.h>
using namespace std;

class NiceOrUgly {
    public:
        string describe(string s) {
            int n = s.size();
            int v = 0, c = 0;
            vector<vector<bool>> dp(n, vector<bool>(2, false));
            bool isUgly = false, isNice = true;
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == '?') {
                    v++;
                    c++;
                } else if (isVowel(s[i])) {
                    v++;
                    c = 0;
                } else {
                    c++;
                    v = 0;
                }

                if (v >= 3) {
                    isUgly = true;

                    // try to keep nice
                    bool isCurUgly = true;
                    int ptr = 0;
                    while (++ptr < 3) {
                        if (s[ptr + i] == '?') {
                            isCurUgly = isCurUgly && dp[ptr + i][1];
                        }
                    }

                    dp[i][0] = isCurUgly;
                    cout << dp[i][0] << endl;
                }

                if (c >= 5) {
                    isUgly = true;

                    // try to keep nice
                    bool isCurUgly = true;
                    int ptr = 0;
                    while (++ptr < 5) {
                        if (s[ptr + i] == '?') {
                            isCurUgly = isCurUgly && dp[ptr + i][0];
                        }
                    }

                    dp[i][1] = isCurUgly;
                }

                if (s[i] == '?' && (v >= 3 || c >= 5)) {
                    isNice = isNice && (!dp[i][0] || !dp[i][1]);
                } else if (v >= 3) {
                    isNice = isNice && !dp[i][v];
                } else if (c >= 5) {
                    isNice = isNice && !dp[i][1];
                }
            }
            
            if (s.find("?") == string::npos) {
                if (isUgly) return "UGLY";
                else return "NICE";
            }

            if (isUgly && isNice) return "42";
            else if (isUgly) return "UGLY";
            return "NICE";
        }

    private:

        bool isVowel(char c) {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
            return false;
        }
};
