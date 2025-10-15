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
        vector<bool> isCamera;

        bool isPos(int numCamera) {
            isCamera = vector<bool>(n, false);
            while(numCamera--) {
                isCamera[numCamera] = true;
            }

            for (int i = 0; i < n; i++) {
                if (!checkCamera(i)) return false;
            }

            return true;
        }

        // check if need a camera on this node or not, and if yes can we put it or not
        bool checkCamera(int curNode) {
            if (isCamera[curNode]) {
                return true;
            }

            for (int to : adj[curNode]) {
                if (!isCamera[to]) {
                    // need to put camera on  curNode
                    isCamera[curNode] = true;
                    if (freeCamera()) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }

            return true;
        }

        bool freeCamera() {
            for (int i = 0; i < n; i++) {
                if (isCamera[i] && ifFree(i)) {
                    isCamera[i] = false;
                    return true;
                }
            }

            return false;
        }

        bool ifFree(int node) {
            for (int to : adj[node]) {
                if (!isCamera[to]) return false;
            }

            return true;
        }
};