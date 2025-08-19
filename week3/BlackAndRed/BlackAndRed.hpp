#include <bits/stdc++.h>
using namespace std;

class BlackAndRed {
public:
    int cut(string deck) {
        int red, black = 0;
        int cut = 0, idx = 1;
        for (char c : deck) {
            if (c == 'R') red++;
            else black++;

            if (red > black) {
                cut = idx;
                red = 0; black = 0;
            }

            idx++;
        }

        return cut;
    }
};