#include <bits/stdc++.h>
using namespace std;

class FillBox
{
public:
    int minNumber(vector<int> pleasantness, int variety) {
        int minValue = INT_MAX, maxValue = INT_MIN;
        for (int i = 0; i < pleasantness.size(); i++) {
            minValue = min(minValue, pleasantness[i]);
            maxValue = max(maxValue, pleasantness[i]);

            if (maxValue - minValue <= variety) {
                return (i / 2) + 1;
            }
        }

        return pleasantness.size();
    }

    private:
};
