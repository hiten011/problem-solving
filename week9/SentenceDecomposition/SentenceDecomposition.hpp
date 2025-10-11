#include <bits/stdc++.h>
using namespace std;

class SentenceDecomposition {
public:
    int decompose(string sentence, vector<string> validWords) {
        unordered_map<int, vector<string>> sizeToWords;
        for (string &s : validWords) {
            sizeToWords[s.size()].push_back(s);
        }

        // DP
        int n = sentence.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = i; j < n; j++) {
                if (dp[i] == INT_MAX) continue;

                s += sentence[j];
                int cost = helper(s, sentence, sizeToWords);

                if (cost == INT_MAX) continue;

                // update dp
                dp[j + 1] = min(dp[j + 1], dp[i] + cost);
            }

        }

        return (dp[n] == INT_MAX ? -1 : dp[n]);
    }

private:
    int helper(string &s, string &sentence, unordered_map<int, vector<string>> &sizeToWords) {
        if (sizeToWords.count(s.size()) == 0) return INT_MAX;

        int minCost = INT_MAX;
        for (string &str : sizeToWords[s.size()]) {
            int curCost = findCost(s, str);
            minCost = min(curCost, minCost);
        }

        return minCost;
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