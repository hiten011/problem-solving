#include <bits/stdc++.h>
using namespace std;

class JumpyNum {
    public:
        int howMany(int low, int high) {
            if (low == 0) low = 1;
            string l = to_string(low - 1), h = to_string(high);
            int ans = helper(h, 0, true, 11);
            cout << ans << endl;

            int lAns = (l.size() == 1 ? getInt(l[0]) + 1 : helper(l, 0, true, 11));
            cout << lAns << endl;

            return ans - lAns;
        }
    
    private:
        int helper(string &num, int idx, bool isUpper, int prev) {
            if (idx == num.size()) return 1;
            
            int ans = 0, en = (isUpper ? getInt(num[idx]) : 9), st = (prev == 11 ? 1 : 0);
            for (int i = st; i <= en; i++) {
                if (i == prev || i == prev + 1 || i == prev - 1) continue;

                if (isUpper && i == en) {
                    ans += helper(num, idx + 1, true, i);
                } else {
                    ans += helper(num, idx + 1, false, i);
                }
            }

            if (idx != num.size() - 1 && prev == 11) ans += helper(num, idx + 1, false, 11);
            return ans;
        }  

        int getInt(char c) {
            return (int) (c - '0');
        }
};