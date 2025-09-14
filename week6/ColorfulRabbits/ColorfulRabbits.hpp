#include <bits/stdc++.h>
using namespace std;

class ColorfulRabbits
{
public:
    int getMinimum(vector<int> replies) {
        unordered_map<int, int> freq;
        for (int i : replies) {
            freq[i + 1]++;
        }

        int count = 0;
        for (pair<int, int> p : freq) {
            int num = (p.second % p.first);

            count += (p.second - num);
            count += (num == 0 ? 0 : p.first);
        }

        return count;
    }

private:
};
