#include <bits/stdc++.h>
using namespace std;

class CircularLine {
  public:
    int n, ans;

    int longestTravel(vector<int> t) {
        n = t.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(calcDis(i, j, t), ans);
            }
        }

        return ans;
    }

    int calcDis(int x, int y, vector<int> &d) {
        // forward dis
        int forDis = dis(x, y, d);
        // backDis
        int backDis = dis(0, x, d) + dis(y, n, d);

        return min(backDis, forDis);
    };

    int dis(int x, int y, vector<int> &vec) {
        int dis = 0;
        for (int i = x; i < y; i++) {
            dis += vec[i];
        }

        return dis;
    };
};