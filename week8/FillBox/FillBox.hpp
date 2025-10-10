#include <bits/stdc++.h>
using namespace std;

class FillBox
{
public:
    int minCubes(int length, int width, int height, vector<int> cubes) {
        long long vol = length * width * height;
        int ans = 0;
        for (int i = cubes.size() - 1; i >= 0; i--) {
            if (vol == 0) return ans; // vol reaches 0

            long long curVol = (long long)pow(pow(2, i), 3); 
            if (vol < curVol) continue;

            int num = min(cubes[i], (int) (vol / curVol));
            ans += num;
            vol = vol - (num * curVol);
        }

        return (vol > 0 ? -1 : ans);
    }

private:
};
