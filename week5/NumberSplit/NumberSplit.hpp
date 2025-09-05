#include <bits/stdc++.h>
using namespace std;

class NumberSplit {
    public:
        int longestSequence(int start) {
            vector<int> dp(start + 1, 0);
            for (int i = 0; i <= min(start, 9); i++) {
                dp[i] = 1;
            }

            for (int i = 10; i <= start; i++) {
                unordered_set<int> us;
                string num = to_string(i);
                vector<bool> isSplit(num.size(), false);
                isSplit[num.size() - 1] = true;

                rec(num, isSplit, us, 0);
                // cout << num << ": " << endl;
                for (int j : us) {
                    // cout << j << " ";
                    dp[i] = max(dp[j], dp[i]);
                }
                dp[i]++;
            }

            return dp[start];
        }

    private:
        void rec(const string &s, vector<bool> &isSplit, unordered_set<int> &us, int idx) {
            if (idx == isSplit.size() - 1) {
                us.insert(calc(s, isSplit));
                return;
            }

            // not split
            rec(s, isSplit, us, idx + 1);

            // split
            isSplit[idx] = true;
            rec(s, isSplit, us, idx + 1);
            isSplit[idx] = false;
        }

        int calc(const string &s, vector<bool> &isSplit) {
            int prev = 0, ans = 1;
            for (int i = 0; i < isSplit.size(); i++) {
                if (isSplit[i]) {
                    ans *= stoi(s.substr(prev, i - prev + 1));
                    prev = i + 1;
                }
            }
            
            // cout << ans << endl;
            return ans;
        } 
};