#include <bits/stdc++.h>
using namespace std;

class DownloadingFiles {
public:
    double actualTime(vector<string> tasks) {
        int idx = 0;
        int totalTime = 0, totalSpeed = 0;
        for (string str : tasks) {
            pair<int, int> cur = split(str);

            totalTime += cur.second;
            totalSpeed += cur.first;
        }

        cout << totalTime << " " << totalSpeed << endl;
        return (double) totalTime / totalSpeed;
    }
private:
    pair<int, int> split(const string &str) {
        int i = 0;
        while (i < str.size()) {
            if (str[++i] == ' ') break;
        }

        return {stoi(str.substr(0, i)), stoi(str.substr(i + 1))};
    }
};