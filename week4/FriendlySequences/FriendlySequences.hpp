#include <bits/stdc++.h>
using namespace std;

class FriendlySequences {
    public:
        int count(vector<int> array) {
            vector<bool> prev(10, false);
            int total = 0, ans = 0;
            for (int i : array) {
                vector<bool> cur = to_freq(i);

                if (isMatch(prev, cur)) {
                    total++;
                } else {
                    prev = cur;
                    ans += ((total * (total - 1)) / 2);
                    total = 1;
                }
            }

            ans += ((total * (total - 1)) / 2);
            return ans;
        }

        vector<bool> to_freq(int num) {
            vector<bool> freq(10, false);
            while (num > 0) {
                int digit = num % 10;
                freq[digit] = true;

                num /= 10;
            }

            return freq;
        }

        bool isMatch(vector<bool> freq1, vector<bool> freq2) {
            for (int i = 0; i < 10; i++) {
                if (freq1[i] != freq2[i]) return false;
            }

            return true;
        }
};