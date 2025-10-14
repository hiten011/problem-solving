#include <bits/stdc++.h>
using namespace std;

class CubeStickers {
    public:
        string isPossible(vector<string> sticker) {
            unordered_map<string, int> freq;
            for (string s : sticker) {
                freq[s]++;
            }
            
            int ans = 6;
            for (pair<string, int> p : freq) {
                ans -= min(2, p.second);
            }

            return (ans <= 0 ? "YES" : "NO");
        }   

    private:
};