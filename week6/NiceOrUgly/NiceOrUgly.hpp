#include <bits/stdc++.h>
using namespace std;

class NiceOrUgly {
    public:
        string describe(string s) {
            int n = s.size();
            bool isU = isUgly(s, n, true);

            if (!isU) return "NICE";

            bool isN = !isUgly(s, n, false);
            if (isN) {
                return "42";
            }

            return "UGLY";
        }

    private:

        bool isUgly(string &s, int n, bool withQ) {
            // check for Ugly

            // conso
            int st = 0, en = 0;
            int count = 0;
            while (en < 5 && en < n) {
                if (s[en] == '?' && withQ || s[en] != '?' && !isVowel(s[en])) count++;
                else count = 0;

                en++;
            }

            while (en < n) {
                if (count == 5) return true;

                if (s[en] == '?' && withQ || s[en] != '?' && !isVowel(s[en])) count++;
                else count = 0;

                en++;
            }

            if (count == 5) return true;

            // vowoles
            st = 0; en = 0;
            count = 0;
            while (en < 3 && en < n) {
                if (s[en] == '?' && withQ || s[en] != '?' && isVowel(s[en])) count++;
                else count = 0;

                en++;
            }

            while (en < n) {
                if (count == 3) return true;

                if (s[en] == '?' && withQ || s[en] != '?' && isVowel(s[en])) count++;
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
