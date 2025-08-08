#include <bits/stdc++.h>
using namespace std;

class PartySeats {
  public:
    vector<string> boys, girls;
    vector<string> seating(vector<string> attendees) {
        // parsing input
        int n = attendees.size();
        vector<string> ans(n + 2);
        for (string &s : attendees) {
            size_t start = 0, end;
            end = s.find(" ", start);

            string name = s.substr(start, end);
            string gender = s.substr(end + 1);

            if (gender == "boy") boys.push_back(name);
            else girls.push_back(name);
        }
        
        // checking if input is valid
        int nBoys = boys.size(), nGirls = girls.size();
        if (nBoys != nGirls) return ans;
        if (nBoys < 2) return ans;

        // sorting girls and biys lexographically
        sort(boys.begin(), boys.end());
        sort(girls.begin(), girls.end());
        
        // placing people on seats
        ans[0] = "HOST";
        int ptr1 = 0, ptr2 = 0;
        for (int i = 1; i <= n + 1; i++) {
            if ((n / 2) + 1 == i) ans[i] = "HOSTESS";
            else if (i % 2 == 1) ans[i] = girls[ptr1++];
            else ans[i] = boys[ptr2++];
        }

        return ans;
    }
};