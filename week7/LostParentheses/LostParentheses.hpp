#include <bits/stdc++.h>
using namespace std;

class LostParentheses
{
public:
    int minResult(string s)
    {   
        int ans = 0;
        string val = "";
        bool isAdd = true;
        for (char c : s) {
            if (c == '+' || c == '-') {
                int num = stoi(val);
                val = "";

                if (isAdd) ans += num;
                else ans -= num;

                if (c == '+') isAdd = true;
                else isAdd = false;
            } else {
                val += c;
            }
        }

        return ans;
    }

private:
};
