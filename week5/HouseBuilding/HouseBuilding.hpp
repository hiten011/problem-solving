#include <bits/stdc++.h>
using namespace std;

class HouseBuilding {
    public:
        int getMinimum(vector<string> area) {
            vector<int> freq(10, 0);
            for (string s : area) {
                for (char c : s) {
                    freq[getInt(c)]++;
                }
            }

            int st = 0, en = 9, ans = 0;
            while (st < en - 1) {
                if (freq[st] == 0) {
                    st++;
                    continue;
                } else if (freq[en] == 0) {
                    en--;
                    continue;
                } else if (freq[st] < freq[en]) {
                    ans += freq[st];
                    freq[st + 1] += freq[st];
                    freq[st] = 0;
                    st++;
                } else {
                    ans += freq[en];
                    freq[en - 1] += freq[en];
                    freq[en] = 0;
                    en--;
                }
            }

            return ans;
        }

    private:
        int getInt(char c) {
            return (int) (c - '0');
        }
};