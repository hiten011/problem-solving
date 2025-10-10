#include <bits/stdc++.h>
using namespace std;

class ProblemsToSolve
{
public:
    int minNumber(vector<int> pleasantness, int variety) {
        int minIndex = 0, maxIndex = 0;
        for (int i = 0; i < pleasantness.size(); i++) {
            if (pleasantness[i] < pleasantness[minIndex]) {
                minIndex = i;
            } else if (pleasantness[i] == pleasantness[minIndex] && i % 2 == 0) {
                minIndex = i;
            }

            if (pleasantness[i] > pleasantness[maxIndex]) {
                maxIndex = i;
            } else if (pleasantness[i] == pleasantness[maxIndex] && i % 2 == 0) {
                maxIndex = i;
            }

            if (pleasantness[maxIndex] - pleasantness[minIndex] >= variety) {
                if (maxIndex % 2 == 0 && minIndex % 2 == 0) return (i / 2) + 1;
                return (i / 2) + 2;
            }
        }

        return pleasantness.size();
    }

    private:
};
