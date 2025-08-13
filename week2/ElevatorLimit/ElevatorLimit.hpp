#include <bits/stdc++.h>
using namespace std;

class ElevatorLimit
{
public:
    vector<int> getRange(vector<int> enter, vector<int> exit, int physicalLimit) {
        int maxPeople = physicalLimit, curMax = physicalLimit, minPeople = 0, curMin = 0, n = enter.size();
        for (int i = 0; i < n; i++) {
            // update Max
            curMax -= exit[i];
            if (curMax < 0) return {}; // not possible

            curMax += enter[i];
            if (curMax > physicalLimit) {
                int diff = curMax - physicalLimit;
                maxPeople -= diff;
                curMax = physicalLimit;
            }

            if (maxPeople < 0) return {}; // not Possible


            // update Min
            curMin -= exit[i];
            if (curMin < 0) {
                int diff = abs(curMin);
                minPeople += diff;
                curMin = 0;
            }

            if (minPeople > physicalLimit) return {};

            curMin += enter[i];
            if (curMin > physicalLimit) return {};
        }

        return {minPeople, maxPeople};
    }
};