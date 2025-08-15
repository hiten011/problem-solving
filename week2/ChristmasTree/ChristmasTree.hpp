#include <bits/stdc++.h>
using namespace std;

class ChristmasTree
{
public:
    long long decorationWays(int N, int red, int green, int blue)
    {
        return helper(1, N, red, green, blue);
    }

private:
    long long helper(int lvl, int maxLvl, int red, int green, int blue) {
        if (lvl > maxLvl) return 1;
        
        long long ans = 0;

        vector<int> vec(3, 0); // [red: 0, green: 1, blue: 2]

        // try all red
        if (red - lvl >= 0) {
            vec[0] = lvl;

            ans += helper(lvl + 1, maxLvl, red - lvl, green, blue) * perm(vec);

            vec[0] = 0;
        }

        // try all green
        if (green - lvl >= 0) {
            vec[1] = lvl;

            ans += helper(lvl + 1, maxLvl, red, green - lvl, blue) * perm(vec);

            vec[1] = 0;
        }

        // try all blue
        if (blue - lvl >= 0) {
            vec[2] = lvl;

            ans += helper(lvl + 1, maxLvl, red, green, blue - lvl) * perm(vec);

            vec[2] = 0;
        }

        // try to divide bwtween all three
        if (lvl % 3 == 0) {
            int num = lvl / 3;
            if (red < num || blue < num || green < num) {} 
            else {
                // setting to num
                for (int i = 0; i < 3; i++) {
                    vec[i] = num;
                }

                ans += helper(lvl + 1, maxLvl, red - num, green - num, blue - num)  * perm(vec);
                
                // reset
                for (int i = 0; i < 3; i++) {
                    vec[i] = 0;
                }
            }
        }

        // try red-blue and red-green
        if (lvl % 2 == 0) {
            int num = lvl / 2;

            if (red >= num) {
                vec[0] = num;

                // try blue
                if (blue >= num) {
                    vec[2] = num;

                    ans += helper(lvl + 1, maxLvl, red - num, green, blue - num)  * perm(vec);

                    vec[2] = 0;
                }

                // try green
                if (green >= num) {
                    vec[1] = num;

                    ans += helper(lvl + 1, maxLvl, red - num, green - num, blue) * perm(vec);

                    vec[1] = 0;
                }

                vec[0] = 0;
            }
        }

        // try blue-green
        if (lvl % 2 == 0) {
            int num = lvl / 2;

            if (blue >= num && green >= num) {
                vec[1] = num;
                vec[2] = num;

                ans += helper(lvl + 1, maxLvl, red, green - num, blue - num)  * perm(vec);

                vec[1] = 0;
                vec[2] = 0;
            }
        }

        return ans;
    }

    long long perm(vector<int> &freq) {
        long long ans = 0;
        ans += fact(freq[0] + freq[1] + freq[2]);
        
        for (int i : freq) {
            ans /= fact(i);
        }

        return ans;
    };

    unordered_map<int, long long> factorials;
    long long fact(int num) {
        if (num == 0) return 1;
        if (factorials.count(num) != 0) {
            return factorials[num];
        }

        return factorials[num] = num * fact(num - 1);
    }
};