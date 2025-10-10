#include <bits/stdc++.h>
using namespace std;

class RockStar
{
public:
    int getNumSongs(int ff, int fs, int sf, int ss) {
        int ans = ff;
        
        if (!ff && !fs) {
            ans += ss;
            ans += min(sf, 1);
            return ans;
        }

        if (!fs) return ans;

        ans++;
        fs--;

        ans += ss;
        ans += 2 * min(sf, fs);

        return ans;
    }

private:
};
