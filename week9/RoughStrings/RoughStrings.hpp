#include <bits/stdc++.h>
using namespace std;

class RoughStrings {
public:
    int minRoughness(string s, int n) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[getInt(c)]++;
        }

        sort(freq.begin(), freq.end());
        int st = 0, en = 25, roughness = INT_MAX;
        while (st < en && n > -1) {
            if (freq[st] == 0) {
                st++;
                continue;
            }
            
            roughness = min(abs(freq[st] - freq[en]), roughness);
            freq[st]--;
            n--;
        }

        return roughness;
    }

private:
    int getInt(char c) {
        return (int) (c - 'a');
    }
};