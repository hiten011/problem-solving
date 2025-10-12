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
    unordered_map<string, unordered_map<int, unordered_map<int, int>>> memo;
    int rec(vector<int> &freq, int n, int idx) {
        if (idx == freq.size()) {
            return calcRoughness(freq);
        }

        string str = getString(freq);
        if (memo.count(str) > 0 && memo[str].count(n) > 0 && memo[str][n].count(idx) > 0) {
            return memo[str][n][idx];
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

        return memo[str][n][idx] = ans;
    }

    string getString(vector<int> &freq) {
        sort(freq.begin(), freq.end());
        string str = "";
        for (int i : freq) {
            if (i == 0) continue;
            str += to_string(i) + "/";
        }

        return str;
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