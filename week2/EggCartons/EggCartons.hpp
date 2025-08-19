#include <bits/stdc++.h>
using namespace std;

class EggCartons
{
public:
    int minCartons(int n) {
        if (n % 2 == 1) return -1;
        
        int x = 0;
        while (n >= 6*x && (n - 6*x) % 8 != 0) {
            x++;
        }

        return n < 6*x ? -1 : x + ((n - 6 * x) / 8);
    }
};