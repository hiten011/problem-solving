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
        n -= len;
        int diff = abs(hn - num);
        if (n >= 0 && ((n % 2 == 0 && diff % 2 == 0) || (n % 2 == 1 && diff % 2 == 1))) {
            return "YES";
        } else {
            return "NO";
        }
    }
};