#include <bits/stdc++.h>
using namespace std;

class RockStar
{
public:
    int getNumSongs(int ff, int fs, int sf, int ss) {
        int ans = 0;
        if (fs > 0) {
            ans += ff;
        } else if (ff != 0) {
            return ff;
        }

        if (fs > 0) {
            ans += fs;
        } else {
            return ss + sf;
        }

        return ans + ss + sf;
    }

private:
};
