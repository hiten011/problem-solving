#include <bits/stdc++.h>
using namespace std;

class EggCartons
{
public:
    int minCartons(int n) {
        int mod = n % 8;
        return 0;
    }

    double ans = 0;
    double getProb(int steps, double n, double s, double e, double w) {
        unordered_set<string> visited;
        ans = 0;
        helper(steps, n, s, e, w, visited, 15, 15, 1);
        return ans;
    }

    void helper(int steps, double n, double s, double e, double w, unordered_set<string> &visited, int x, int y, double p) {
        if (visited.count(getString(x, y))) return;
        if (steps == 0) {
            ans += p; 
            return;
        }
        
        visited.insert(getString(x, y));

        // move north
        helper(steps - 1, n, s, e, w, visited, x, y + 1, p * n);

        // move east
        helper(steps - 1, n, s, e, w, visited, x - 1, y, p * e);

        // move south
        helper(steps - 1, n, s, e, w, visited, x, y - 1, p * s);

        // move west
        helper(steps - 1, n, s, e, w, visited, x + 1, y, p * w);

        visited.erase(getString(x, y));
    }  
    
    string getString(int x, int y) {
        return (to_string(x) + "/" + to_string(y));
    }
};