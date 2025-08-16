#include <bits/stdc++.h>
using namespace std;

class DerivativeSequence
{
public:
    vector<int> derSeq(vector<int> a, int n) {
        while (n--) {
            for (int i = 0; i < a.size() - 1; i++) {
                a[i] = a[i + 1] - a[i];
            }

            a.pop_back();
        }

        return a;
    }
};