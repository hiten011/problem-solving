#include <bits/stdc++.h>
using namespace std;

class SimpleCompressor
{
public:
    string uncompress(string data) {
        stack<char> st1;
        for (char c : data) {
            st1.push(c);
        }

        stack<char> st2;
        while (!st1.empty()) {
            char cur = st1.top();
            st1.pop();

            if (cur == '[') {
                decompress(st2);
            } else {
                st2.push(cur);
            }
        }

        string ans = "";
        while (!st2.empty()) {
            ans += st2.top();
            st2.pop();
        }

        return ans;
    }

private:
    void decompress(stack<char> &st) {
        int num = (int) (st.top() - '0');
        st.pop();

        string ans = "";
        while (!st.empty() && st.top() != ']') {
            ans += st.top();
            st.pop();
        }
        st.pop(); // remove ']'

        string res = "";
        while (num--) {
            res += ans;
        }

        for (int i = res.size() - 1; i >= 0; i--) {
            st.push(res[i]);
        }
    }
};