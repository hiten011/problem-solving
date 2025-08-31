#include <bits/stdc++.h>
using namespace std;

class MonstersValley2 {
    public:
        int minimumPrice(vector<int> dread, vector<int> price)
        {
            return helper(dread, price, 0, 0, 0);
        }

        int helper(vector<int> &dread, vector<int> &price, int idx = 0, int party = 0, int cost = 0) {
            if (idx == dread.size()) return cost;
            
            // bribe
            int ans = helper(dread, price, idx + 1, party + dread[idx], cost + price[idx]);
            if (party >= dread[idx]) {
                // not-bribe
                ans = min(helper(dread, price, idx + 1, party, cost), ans);
            }

            return ans;
        }
};