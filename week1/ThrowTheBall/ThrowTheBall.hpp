#include <bits/stdc++.h>
using namespace std;

class Inchworm {
  public:
    int timesThrown(int N, int M, int L) {
        vector<int> p(N, 0);
        p[0] = 1;

        int idx = 0, ans = 0;
        while (p[idx] < M) {
            if (p[idx] % 2 == 0) {
                // even
                idx = (idx - L + N) % N; // just the val dosn't becomes neg
            } else {
                // odd
                idx = (idx + L) % N;
            }

            p[idx]++;
            ans++;
        }
    }
};