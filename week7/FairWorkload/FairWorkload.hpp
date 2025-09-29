#include <bits/stdc++.h>
using namespace std;

class FairWorkload {
    public:
        int getMostWork(vector<int> folders, int workers) {
            int sum = 0;
            for (int i : folders) {
                sum += i;
            }

            int st = 0, en = sum;
            while (st < en) {
                int mid = (st + en) / 2;

                if (isPos(mid, folders, workers)) {
                    en = mid;
                } else {
                    st = mid + 1;
                }
            }

            return st;
        }

    private:
        bool isPos(int num, vector<int> &folders, int workers) {
            int curSum = 0, cab = 0;
            for (int i = 0; i < folders.size(); i++) {
                if (folders[i] > num) return false;
                curSum += folders[i];

                if (curSum > num) {
                    cab++;
                    curSum = folders[i - 1];
                }
            }

            return cab <= workers;
        }
};
