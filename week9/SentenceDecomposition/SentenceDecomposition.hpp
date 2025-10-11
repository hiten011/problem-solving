#include <bits/stdc++.h>
using namespace std;

class SentenceDecomposition {
public:
    int decompose(string sentence, vector<string> validWords) {
        unordered_map<int, vector<string>> sizeToWords;
        for (string &s : validWords) {
            sizeToWords[s.size()].push_back(s);
        }

        vector<vector<int>> cost; // [endIdx, stIdx, cost]
        int n = sentence.size();
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = i; j < n; j++) {
                s += sentence[j];
                helper(s, sentence, cost, sizeToWords, i, j);
            }
        }

        // DP
        sort(cost.begin(), cost.end(), [](vector<int> &a, vector<int> &b){
            return (a[1] == b[1] ? a[0] < b[0] : a[1] < b[1]);
        });

        // for (vector<int> &i : cost) {
        //     cout << i[0] << " " << i[1] << " " << i[2] << endl;
        // }

        vector<int> dp(n + 1, INT_MAX);
        if (cost.size() == 0 || cost[0][1] != 0) return -1;

        dp[0] = 0;
        for (vector<int> &i : cost) {
            if (dp[i[1]] == INT_MAX) continue;

            int curCost = dp[i[1]] + i[2];
            dp[i[0] + 1] = min(dp[i[0] + 1], curCost);
        }

        return dp[n];
    }

private:
    void helper(string &s, string &sentence, vector<vector<int>> &cost, unordered_map<int, vector<string>> &sizeToWords, int st, int en) {
        if (sizeToWords.count(s.size()) == 0) return;

        int minCost = INT_MAX;
        for (string &str : sizeToWords[s.size()]) {
            int curCost = findCost(s, str);
            minCost = min(curCost, minCost);
        }

        if (minCost == INT_MAX) return;
        cost.push_back({en, st, minCost});
    }

    int findCost(string &s, string &match) {
        vector<int> freqS(26, 0), freqM(26, 0);
        int cost = 0;
        for (int i = 0; i < s.size(); i++) {
            freqS[getInt(s[i])]++;
            freqM[getInt(match[i])]++;

            if (s[i] != match[i]) {
                cost++;
            }
        }

        return (freqS == freqM ? cost : INT_MAX);
    }

    int getInt(char c) {
        return (int) (c - 'a');
    }
};