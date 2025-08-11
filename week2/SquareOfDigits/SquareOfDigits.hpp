#include <bits/stdc++.h>
using namespace std;

class SquareOfDigits { 
    public:
        int getMax(vector<string> data) {
            int ans = 1;
            int m= data[0].size(), n = data.size();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int idx = 0;
                    while (i + idx < n && j + idx < m) {
                        char num = data[i][j];
                        if (data[i + idx][j] == num && data[i][j + idx] == num && data[i + idx][j + idx] == num) ans = max(idx + 1, ans);

                        idx++;
                    }
                }
            }

            return ans * ans;
        };
};