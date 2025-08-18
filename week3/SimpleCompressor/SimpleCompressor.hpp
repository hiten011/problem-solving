#include <bits/stdc++.h>
using namespace std;

class SimpleCompressor
{
public:
    string uncompress(string data) {
        stack<char> st;
        for (char c : data) {
            st.push(c);
        }

        string ans = "", compressed = "";
        bool isCompress = false;
        while (!st.empty()) {
            char cur = st.top();
            st.pop();

            if (cur == ']') {
                isCompress = true;
            } else if (cur == '[') {
                reverse(compressed.begin(), compressed.end());
                string temp = decompress(compressed);
                reverse(temp.begin(), temp.end());

                ans += temp;

                compressed = "";
                isCompress = false;
            } else if (isCompress) {
                compressed += cur;
            } else {
                ans += cur;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    string decompress(string str) {
        int num = stoi(string(1, str[0]));
        string temp = str.substr(1);

        string result;
        for (int i = 0; i < num; i++) {
            result += temp;
        }

        return result;
    }
};