#include <bits/stdc++.h>
using namespace std;

class QuickSums
{
public:
    int minSums(string numbers, int sum) {
        int n = numbers.size() - 1;
        vector<bool> add(n, false); // [false: i,(i+1)] [true: i + (i + 1)] 
        int ans = rec(numbers, sum, add, 0);
        return ans == INT_MAX ? -1 : ans;
    }

    int rec(string &num, int sum, vector<bool> &add, int idx) {
        if (idx == add.size()) {
            if (evaluate(num, add) == sum) return 0;
            return INT_MAX;
        }
        
        int ans = INT_MAX;

        // don't include a sign
        ans = min(rec(num, sum, add, idx + 1), ans);

        // put a sign
        add[idx] = true;

        int temp = rec(num, sum, add, idx + 1);
        ans = min((temp == INT_MAX ? INT_MAX : temp + 1), ans);

        add[idx] = false; // backtrack

        return ans;
    }

    int evaluate(string &num, vector<bool> &add) {
        string temp(1, num[0]);
        int sum = 0;
        for (int i = 1; i < num.size(); i++)
        {
            if (add[i - 1]) {
                sum += stoi(temp);
                temp = string(1, num[i]);
            }
            else {
                temp += num[i];
            }
        }
        sum += stoi(temp);
        return sum;
    }
};