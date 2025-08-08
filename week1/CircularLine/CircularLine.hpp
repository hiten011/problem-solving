#include <bits/stdc++.h>
using namespace std;

class CircularLine {
  public:
    int n, ans;
    vector<int> prefix;

    int longestTravel(vector<int> t) {
        n = t.size(), ans = 0;
        createPrefixSuffix(t);
        
        // sliding window
        int st = 0, en = 1;
        while (en < n) {
            int forDis = prefix[en] - prefix[st]; // forward dis
            int backDis = prefix[st] - prefix[0] + prefix[n] - prefix[en]; // backDis

            if (forDis <= backDis) {
                ans = max(ans, forDis);
                en++;
            } else {
                ans = max(backDis, ans);
                st++;
            }
        }

        return ans;
    };

    void createPrefixSuffix(vector<int> &dis) {
        prefix = vector<int>(n + 1, 0);

        // populating prefix
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + dis[i - 1];
        }
    };
};