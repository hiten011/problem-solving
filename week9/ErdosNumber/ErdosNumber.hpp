#include <bits/stdc++.h>
using namespace std;

class ErdosNumber {
    public:
        vector<string> calculateNumbers(vector<string> publications) {
            unordered_map<string, vector<string>> adj;
            set<string> nodes;
            for (string &i : publications) {
                vector<string> authors;

                string str = "";
                i += " ";
                for (char c : i) {
                    if (c == ' ') {
                        authors.push_back(str);
                        str = "";
                        continue;
                    }

                    str += c;
                }

                for (string u : authors) {
                    for (string v : authors) {
                        if (v == u) continue;
                        adj[u].push_back(v);
                        adj[v].push_back(u);

                        // insert in nodes
                        nodes.insert(u);
                        nodes.insert(v);
                    }
                }
            }
            
            // verify edges
            // for (auto [k, v] : adj) {
            //     cout << k << ": ";
            //     for (auto i : v) {
            //         cout << i << " ";
            //     }

            //     cout << endl;
            // }

            // BFS
            unordered_map<string, int> number;

            int score = 0;
            queue<string> q;
            q.push("ERDOS");
            q.push("#");
            while (q.size() > 1) {
                string cur = q.front();
                q.pop();

                if (number.count(cur) > 0) { // already visited
                    continue;
                }

                if (cur == "#") {
                    q.push("#");
                    score++;
                    continue;
                }
                
                number[cur] = score;
                for (string &str : adj[cur]) {
                    q.push(str);
                }
            }

            vector<string> ans;
            for (string s : nodes) {
                if (number.count(s) > 0) {
                    ans.push_back(s + " " + to_string(number[s]));
                } else {
                    ans.push_back(s + " 0");
                }

                cout << ans[ans.size() - 1] << " ";
            }

            cout << endl;

            return ans;
        }

    private:
};