#include <bits/stdc++.h>
using namespace std;

class ProblemsToSolve
{
public:
    int minNumber(vector<int> pleasantness, int variety) {
        int oddMinIndex = 1, oddMaxIndex = 1, evenMinIndex = 0, evenMaxIndex = 0;
        int ans = pleasantness.size();
        for (int i = 1; i < pleasantness.size(); i++) {

            if (i % 2 == 0 && pleasantness[i] <= pleasantness[evenMinIndex]) {
                evenMinIndex = i;
            }

            if (i % 2 == 1 && pleasantness[i] <= pleasantness[oddMinIndex]) {
                oddMinIndex = i;
            }

            if (i % 2 == 0 && pleasantness[i] >= pleasantness[evenMaxIndex]) {
                evenMaxIndex = i;
            }

            if (i % 2 == 1 && pleasantness[i] >= pleasantness[oddMaxIndex]) {
                oddMaxIndex = i;
            }

            // cout << oddMinIndex<< " :min" << endl;

            int maxValue = max(pleasantness[oddMaxIndex], pleasantness[evenMaxIndex]);
            int minValue = min(pleasantness[oddMinIndex], pleasantness[evenMinIndex]);

            if (pleasantness[evenMaxIndex] - pleasantness[evenMinIndex] >= variety) {
                ans = min(((i / 2) + 1), ans);
                // cout << ans << " :EVEN" << endl;
            } else if (maxValue - minValue >= variety) {
                ans = min(((i / 2) + 2), ans);
                // cout << ans << " :ODD" << endl;
            }
        }

        return ans;
    }

    private:
};
