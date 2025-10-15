#include <bits/stdc++.h>
using namespace std;

class TrafficMonitor {
    public:
        int getMin(vector<string> links) {
            n = links.size();
            adj = vector<vector<int>>(n, vector<int>());
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (links[i][j] == 'Y') {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
            
            int st = 0, en = n - 1;
            while (st < en) {
                int mid = (st + en - 1) / 2;
                cout << mid << endl;

                if (isPos(mid)) {
                    en = mid;
                } else {
                    st = mid + 1;
                }
            }

            return st;
        }

    private:
        int n;
        vector<vector<int>> adj;

        bool isPos(int k) {
            unsigned long long set = (1ULL << k) - 1;
            unsigned long long limit = (1ULL << n);

            while (set < limit) {
                
                // current combination
                vector<bool> isCamera(n, false);
                for (int i = n - 1; i >= 0; i--) {
                    isCamera[i] = ((set >> i) & 1);
                }

                if (isCovered(isCamera)) {
                    return true;
                }

                // Gosper’s hack
                unsigned long long c = set & -set;
                unsigned long long r = set + c;
                set = (((r ^ set) >> 2) / c) | r;
            }

            return false;
        }

        bool isCovered(vector<bool> &isCamera) {
            for (int i = 0; i < n; i++) {
                if (isCamera[i]) continue;
                for (int to : adj[i]) {
                    if (!isCamera[to]) return false;
                }
            }

            return true;
        }

};