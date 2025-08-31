#include <bits/stdc++.h>
using namespace std;

class MonstersValley2 {
    public:
        int minimumPrice(vector<int> dread, vector<int> price, int idx = 0, long long party = 0, int cost = 0) {
            if (idx == dread.size()) return cost;
            
            // bribe
            int ans = minimumPrice(dread, price, idx + 1, party + dread[idx], cost + price[idx]);
            if (party >= dread[idx]) {
                // not-bribe
                ans = min(minimumPrice(dread, price, idx + 1, party, cost), ans);
            }

            return ans;
        }
};