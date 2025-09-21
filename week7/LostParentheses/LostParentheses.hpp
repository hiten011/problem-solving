#include <bits/stdc++.h>
using namespace std;

class LostParentheses
{
public:
    int minResult(string s)
    {   
        if (s[0] != '-' && s[0] != '+') {
            s = '+' + s;
        }

        int ans1 = 0, ans2 = -1;
        bool isFirst = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+') {
                pair<int, int> p = getNum(i + 1, s);
                int num = p.first;
                i = p.second;

                ans1 += num;
            } else if (s[i] == '-' && isFirst) {
                isFirst = false;
                ans2 = ans1;
                ans1 = 0;

                pair<int, int> p = getNum(i + 1, s);
                int num = p.first;
                i = p.second;

                ans1 += num;
            } else if (s[i] == '-') {
                pair<int, int> p = getNum(i + 1, s);
                int num = p.first;
                i = p.second;

                ans1 -= num;
            }
        }

        return (ans2 == -1 ? ans1 : ans2 - ans1);
    }

    pair<int, int> getNum(int idx, string &s) {
        string num = "";
        int j = idx;
        for (j = idx; j < s.size(); j++) {
            if (s[j] == '+' || s[j] == '-') break;
            num += s[j];
        }

        return {stoi(num), j - 1};
    }

private:
};
