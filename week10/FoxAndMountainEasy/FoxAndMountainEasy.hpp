#include <bits/stdc++.h>
using namespace std;

class FoxAndMountainEasy {
public:
    string possible(int n, int h0, int hn, string history) {
        int num = h0;
        for (char c : history) {
            if (c == 'U') {
                num++;
            } else {
                num--;
            }
        }

        n -= history.size();
        return (abs(num - hn) <= n ? "YES" : "NO");
    }
};