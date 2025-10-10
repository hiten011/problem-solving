#include <bits/stdc++.h>
using namespace std;

class ProblemsToSolve
{
public:
    int minNumber(vector<int> pleasantness, int variety) {
        int minIndex = 0;
        for (int i = 0; i < pleasantness.size(); i++) {
            if (pleasantness[i] < pleasantness[minIndex]) {
                minIndex = i;
            }

            if (pleasantness[i] - pleasantness[minIndex] >= variety) {
                return (i / 2) + 1;
            }
        }

        return pleasantness.size();
    }

    private:
};
