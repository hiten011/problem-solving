#include <bits/stdc++.h>
using namespace std;

class DownloadingFiles {
public:
    double actualTime(vector<string> tasks) {
        vector<pair<int, int>> vec;
        for (string str : tasks) {
            
        }

        return 0.0;
    }
private:
    vector<string> split(const string &str, char delimiter) {
        vector<string> tokens;
        string token;
        stringstream ss(str);

        while (getline(ss, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
};