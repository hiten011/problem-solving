#include <bits/stdc++.h>
using namespace std;

class NiceOrUgly {
    public:
        string describe(string s) {
            int n = s.size();
            bool isC = isUglyC(s, n);
            bool isV = isUglyV(s, n);


            size_t pos = s.find("?");
            if (pos != string::npos) {
                if (isC && isV) return "UGLY";
                if (!isC && !isV) return "NICE";
                return "42";
            } else {
                if (isC || isV) return "UGLY";
                else return "NICE";
            }
        }

    private:

        bool isUglyC(string s, int n) {
            // check for Ugly
            int en = 0, count = 0;
            while (en < n) {
                if (s[en] == '?') s[en] = 'C';

                if (!isVowel(s[en])) count++;
                else count = 0;

                en++;
                if (count == 5) return true;
            }

            return false;
        }

        bool isUglyV(string s, int n) {
            // check for Ugly
            int en = 0, count = 0;
            while (en < n) {
                if (s[en] == '?') s[en] = 'A';

                if (isVowel(s[en])) count++;
                else count = 0;

                if (count == 3) return true;
                en++;
            }

            return false;
        }

        bool isVowel(char c) {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
            return false;
        }
};
