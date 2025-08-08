#include <bits/stdc++.h>
using namespace std;

class StreetParking {
  public:
    int freeParks(string street) {
        int n = street.size();
        for (int i = 0; i < n; i++) {

            // mark as cannot visit
            if (street[i] == 'D') {
                street[i] = 'X';
            } else if (street[i] == 'S') {
                street[i] = 'X';
                if (i + 1 < n) street[i + 1] = 'X';
                if (i - 1 >= 0) street[i - 1] = 'X';
            } else if (street[i] == 'B') {
                street[i] = 'X';
                if (i - 1 >= 0) street[i - 1] = 'X';
                if (i - 2 >= 0) street[i - 2] = 'X';
            }
        }

        int ans = 0;
        for (auto &i : street) {
            if (i != 'X') ans++;
        }

        return ans;
    }
};