#include <bits/stdc++.h>
using namespace std;

class PaternityTest {
    public:
        vector<int> possibleFathers(string child, string mother, vector<string> men) {
            int n = child.size();
            vector<bool> isMatch(n, false);
            for (int i = 0; i < n; i++) {
                if (mother[i] == child[i]) isMatch[i] = true;
            }
            
            vector<int> ans;
            int idx = 0;
            for (string &s : men) {
                if (isPos(isMatch, s, child)) ans.push_back(idx);
                idx++;
            }

            return ans;
        }

        bool isPos(vector<bool> &isMatch, string &men, string &child) {
            int n = child.size(), total = 0;
            // check remaining first
            for (int i = 0; i < n; i++) {
                if (!isMatch[i] && men[i] != child[i]) return false;
                if (isMatch[i]) total++;
            }
            
            for (int i = 0; i < n; i++) {
                if (isMatch[i] && men[i] == child[i]) total--;
            }

            return total <= (n / 2);
        }
};