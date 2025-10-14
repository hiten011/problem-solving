#include <bits/stdc++.h>
using namespace std;

class RoughStrings {
public:
    int minRoughness(string s, int n) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[getInt(c)]++;
        }

        int maxValue = *max_element(freq.begin(), freq.end());
        int minValue = *min_element(freq.begin(), freq.end());

        int st = 0, en = maxValue, ans = maxValue - minValue;
        for (int i = st; i <= en; i++) {
            for (int j = i; j <= en; j++) {
                if (isPos(i, j, n, freq)) {
                    ans = min(j - i, ans);
                }
            }
        }

        return ans;
    }

private:
    int getInt(char c) {
        return (int) (c - 'a');
    }

    bool isPos(int minV, int maxV, int n, vector<int> &freq) {
        int rE = 0;
        for (int i : freq) {
            if (i < minV) {
                rE += i;
            } else if (i > maxV) {
                rE += (i - maxV);
            }
        }

        return rE <= n;
    }
};