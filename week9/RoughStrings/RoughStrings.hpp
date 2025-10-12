#include <bits/stdc++.h>
using namespace std;

class RoughStrings {
public:
    int minRoughness(string s, int n) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[getInt(c)]++;
        }

        return rec(freq, n, 0);
    }

private:
    int rec(vector<int> &freq, int n, int idx) {
        if (idx == freq.size()) {
            return calcRoughness(freq);
        }

        if (freq[idx] == 0) {
            return rec(freq, n, idx + 1);
        }

        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            freq[idx] -= i;
            ans = min(rec(freq, n - i, idx + 1), ans);
            freq[idx] += i;
        }

        return ans;
    }

    int calcRoughness(vector<int> &freq) {
        int maxValue = INT_MIN, minValue = INT_MAX;
        for (int i : freq) {
            if (i == 0) continue;
            maxValue = max(maxValue, i);
            minValue = min(minValue, i);
        }

        return (maxValue == INT_MAX ? INT_MAX : maxValue - minValue);
    }

    int getInt(char c) {
        return (int) (c - 'a');
    }
};