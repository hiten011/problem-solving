#include <bits/stdc++.h>
using namespace std;

class TomekPhone {
    public:
        int minKeystrokes(vector<int> frequencies, vector<int> keySizes) {
            int totalKeys = accumulate(keySizes.begin(), keySizes.end(), 0);
            if (totalKeys < frequencies.size()) return -1; // if not enough space

            sort(frequencies.begin(), frequencies.end(), greater<int>());
            int n = keySizes.size(), ans = 0, idx = 0;
            vector<int> numKeys(n, 0);
            for (int i = 0; i < frequencies.size();) {
                if (keySizes[idx] != numKeys[idx]) {
                    numKeys[idx]++;
                    ans += (numKeys[idx] * frequencies[i]);
                    i++;
                }

                idx = ((idx + 1) % n);
            }

            return ans;
        };
};