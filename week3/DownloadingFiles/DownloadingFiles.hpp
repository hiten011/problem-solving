#include <bits/stdc++.h>
using namespace std;

class DownloadingFiles {
public:
    double actualTime(vector<string> tasks) {
        vector<pair<int, int>> vec; // [time, speed]
        int idx = 0;
        for (string str : tasks) {
            vec[idx++] = split(str);
        }
    }
private:
    pair<int, int> split(const string &str) {
        int i;
        while (i < str.size()) {
            if (str[i++] == ' ') break;
        }

        return {stoi(str.substr(i + 1)), stoi(str.substr(0, i))};
    }
};