#include <bits/stdc++.h>
using namespace std;

class NiceOrUgly {
    public:
        string describe(string s) {
            int n = s.size();

            // cout << s << endl;

            string str = consc(s);
            if (str != "-1") return str;

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

        string consc(string s) {
            int count = 0;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '?') count++;
                else count = 0;

                if (count == 5) {
                    count--;
                    while (i < s.size() && s[i] == '?') {
                        count++;
                        i++;
                    }

                    string rec1 = describe(s.substr(0, i - count));
                    string rec2 = describe(s.substr(i));

                    if (rec1 == "NICE" || rec1 == "42" || rec2 == "NICE" || rec2 == "42") return "42";
                    else return "UGLY";
                    break;
                }
            }

            return "-1";
        }

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
