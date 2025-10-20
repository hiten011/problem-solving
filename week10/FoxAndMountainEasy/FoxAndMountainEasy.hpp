#include <bits/stdc++.h>
using namespace std;

class FoxAndMountainEasy {
public:
    string possible(int n, int h0, int hn, string history) {
        int num = h0, len = 0;
        for (char c : history) {
            if (c == 'U') {
                num++;
            } else {
                num--;
            }

            if (num < 0) {
                len += 2;
                num = 0;
            } else {
                len++;
            }
        }

        // cout << len << " " << n << " " << num << endl; 
        return (len <= n && abs(num - hn) <= (n - len) ? "YES" : "NO");
    }
};