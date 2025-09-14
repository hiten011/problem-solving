#include <bits/stdc++.h>
using namespace std;

class ShipBoxes
{
public:
    int bestCost(vector<int> box1, vector<int> box2) {
        sort(box1.begin(), box1.end());
        sort(box2.begin(), box2.end());

        vector<int> newDim(3, 0);
        newDim[0] = box1[0] + box2[0];
        for (int i = 1; i < 3; i++) {
            newDim[i] = max(box1[i], box2[i]);
        }

        int ans = 0, minVal = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                ans += 2 * (newDim[i] * newDim[j]);
                minVal = min(minVal, ans);
            }
        }

        return ans + minVal;
    }
private:
};
