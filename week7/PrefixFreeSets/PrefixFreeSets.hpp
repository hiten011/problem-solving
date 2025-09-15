#include <bits/stdc++.h>
using namespace std;

class ShipBoxes
{
public:
    int maxElements(vector<string> words) {
        sort(words.begin(), words.end());

        string prev = "";
        int ans = 0;
        for (string s : words) {
            if (!isPrefix(prev, s)) {
                ans++;
            }
        }

        return ans;
    }
private:
    bool isPrefix(string &s1, string &s2) {
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            if (s1[i] != s2[i]) return false;
        }

        return true;
    }
};
