#include <bits/stdc++.h>
using namespace std;

class CorporationSalary {
public:
    long long totalSalary(vector<string> relations) {
        n = relations.size();
        vector<long long> salaries(n, -1);
        for (int i = 0; i < n; i++) {
            if (salaries[i] == -1) dfs(salaries, i, relations);
        }

        long long ans = 0;
        for (long long i : salaries) {
            if (i == -1) continue;
            ans += i;
        }

        return ans;
    }

private:
    int n = 0;
    long long dfs(vector<long long> &salaries, int curNode, vector<string> &relations) {
        if (salaries[curNode] != -1) return salaries[curNode];
        // cout << curNode << endl;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (relations[curNode][i] == 'Y') {
                ans += dfs(salaries, i, relations);
            }
        }

        return salaries[curNode] = (ans ? ans : 1);
    }
};
