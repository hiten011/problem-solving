#include <bits/stdc++.h>
using namespace std;

class NiceOrUgly {
    public:
        string describe(string s) {
            int n = s.size();
            int v = 0, c = 0;
            bool isUgly = false, isNice = true;
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == '?') {
                    v++;
                    c++;
                } else if (isVowel(s[i])) {
                    v++;
                    c = 0;
                } else {
                    c++;
                    v = 0;
                }

                if (v >= 3) {
                    isUgly = true;
                }

                if (c >= 5) {
                    isUgly = true;
                }

                if (v >= 3 && c >= 5) {
                    isNice = false;
                }
            }
            
            if (s.find('?') == string::npos) {
                if (isUgly) return "UGLY";
                else return "NICE";
            }
            
            if (isUgly && isNice) return "42";
            else if (isUgly) return "UGLY";
            return "NICE";
        }

    private:

        bool isVowel(char c) {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
            return false;
        }
};
