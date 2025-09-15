#include <bits/stdc++.h>
using namespace std;

class LostParentheses
{
public:
    int minResult(string s)
    {   
        int ans = 0;
        string val = "";
        for (char c : s) {
            if (c == '+' || c == '-') {
                int num = stoi(val);
                val = "";

                if (c == '+') ans += num;
                else ans -= num;
            } else {
                val += c;
            }
        }

        return ans;
    }

private:
};
