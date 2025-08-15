#include <bits/stdc++.h>
using namespace std;

class ChristmasTree
{
public:
    long long decorationWays(int N, int red, int green, int blue)
    {
        vector<int> vec(1, -1); // [R: 0, B: 1, G: 2]
        return helper(1, N, red, green, blue, 0, vec);
    }

    long long helper(int lvl, int maxLvl, int red, int green, int blue, int idx, vector<int> &vec) {
        if (lvl > maxLvl) return 1;
        if (idx == lvl) {
            if (isValid(vec)) {
                vector<int> temp(lvl + 1, -1);
                return helper(lvl + 1, maxLvl, red, green, blue, 0, temp);
            } else {
                return 0;
            }
        }
        
        long long ans = 0;

        // try to place red
        if (red > 0) {
            vec[idx] = 0;
            ans += helper(lvl, maxLvl, red - 1, green, blue, idx + 1, vec);
        }

        // try to plac blue
        if (blue > 0) {
            vec[idx] = 1;
            ans += helper(lvl, maxLvl, red, green, blue - 1, idx + 1, vec);
        }

        // try to place green
        if (green > 0) {
            vec[idx] = 2;
            ans += helper(lvl, maxLvl, red, green - 1, blue, idx + 1, vec);
        }

        vec[idx] = -1;
        return ans;
    }

    bool isValid(vector<int> &vec) {
        vector<int> freq(3, 0);
        int record = 0;
        for (int i : vec) {
            freq[i]++;
            record = freq[i];
        }

        if (freq[0] == 0) freq[0] = record;
        if (freq[1] == 0) freq[1] = record;
        if (freq[2] == 0) freq[2] = record;

        if (freq[0] == freq[1] && freq[1] == freq[2]) return true;
        return false;
    }
};