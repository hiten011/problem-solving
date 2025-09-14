#include <bits/stdc++.h>
using namespace std;

class NiceOrUgly {
    public:
        string describe(string s) {
            int n = s.size();
            bool isC = isUglyC(s, n);
            bool isV = isUglyV(s, n);

            if (isC && isV) return "UGLY";
            if (!isC && !isV) return "NICE";
            return "42";
        }

    private:

        bool isUglyC(string s, int n) {
            // check for Ugly
            int st = 0, en = 0;
            int count = 0;
            while (en < 5 && en < n) {
                if (s[en] == '?') s[en] = 'C';

                if (!isVowel(s[en])) count++;
                else count = 0;

                en++;
            }

            while (en < n) {
                if (count == 5) return true;

                if (s[en] == '?') s[en] = 'C';

                if (!isVowel(s[en])) count++;
                else count = 0;

                en++;
            }

            if (count == 5) return true;
            return false;
        }

        bool isUglyV(string s, int n) {
            // check for Ugly
            int st = 0, en = 0;
            int count = 0;
            while (en < 3 && en < n) {
                if (s[en] == '?') s[en] = 'A';

                if (isVowel(s[en])) count++;
                else count = 0;

                en++;
            }

            while (en < n) {
                if (count == 3) return true;

                if (s[en] == '?') s[en] = 'A';

                if (isVowel(s[en])) count++;
                else count = 0;

                en++;
            }

            if (count == 3) return true;
            return false;
        }

        bool isVowel(char c) {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
            return false;
        }
};
