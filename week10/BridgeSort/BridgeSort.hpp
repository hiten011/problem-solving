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

            unordered_map<char, int> order = {
                {'C', 0},
                {'D', 1},
                {'H', 2},
                {'S', 3},
                {'1', 4},
                {'2', 5},
                {'3', 6},
                {'4', 7},
                {'5', 8},
                {'6', 9},
                {'7', 10},
                {'8', 11},
                {'9', 12},
                {'T', 13},
                {'J', 14},
                {'Q', 15},
                {'K', 16},
                {'A', 17}
            };

            sort(str.begin(), str.end(), [&](string &s1, string &s2) {
                return (s1[0] == s2[0] ? order[s1[1]] < order[s2[1]] : order[s1[0]] < order[s2[0]]);
            });

            string ans = "";
            for (string &s : str) {
                ans += s;
            }

            return ans;
        }
};