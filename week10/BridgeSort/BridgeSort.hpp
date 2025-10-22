#include <bits/stdc++.h>
using namespace std;

class BridgeSort {
    public:
        string sortedHand(string hand) {
            vector<string> str;
            string temp = "";
            for (char c : hand) {
                temp += c;

                if (temp.size() == 2) {
                    str.push_back(temp);
                    temp = "";
                } 
            }

            sort(str.begin(), str.end());
            string ans = "";
            for (string &s : str) {
                ans += s;
            }

            return ans;
        }
};