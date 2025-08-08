#include <bits/stdc++.h>
using namespace std;

class CircularLine {
  public:
    int n, ans;
    vector<int> prefix;

    int longestTravel(vector<int> t) {
        n = t.size(), ans = 0;
        createPrefixSuffix(t);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(calcDis(i, j), ans);
            }
        }

        return ans;
    };

    void createPrefixSuffix(vector<int> dis) {
        prefix = vector<int>(n + 1, 0);

        // populating prefix
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + dis[i - 1];
        }
    };

    int calcDis(int x, int y) {
        int forDis = prefix[y] - prefix[x]; // forward dis
        int backDis = prefix[x] - prefix[0] + prefix[n] - prefix[y]; // backDis

        return min(backDis, forDis);
    };
};