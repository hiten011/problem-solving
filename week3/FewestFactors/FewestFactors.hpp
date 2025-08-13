#include <bits/stdc++.h>
using namespace std;

class FewestFactors {
    public:
        int ans = 0, minFac = INT_MAX, n = 0;
        int number(vector<int> digits) {
            ans = -1, minFac = INT_MAX;
            n = digits.size();
            vector<int> nums(n, -1);
            helper(digits, nums, 0);
            return ans;
        };

        void helper(vector<int> &digits, vector<int> &nums, int idx) {
            if (idx == n) {
                int num = convertInt(nums);
                int numFac = findFact(num);
                if (numFac < minFac) {
                    minFac = numFac;
                    ans = num;
                } else if (numFac == minFac && ans > num) {
                    ans = num;
                }

                return;
            }

            for (int i = 0; i < n; i++) {
                if (nums[i] == -1) {
                    // include it here
                    nums[i] = digits[idx];
                    helper(digits, nums, idx + 1);
                    nums[i] = -1;
                }
            }
        };

        int findFact(int num) {
            int fac = 0;
            for (int i = 1; i <= num; i++) {
                if (num % i == 0) fac++;
            }

            // cout << num << " " << fac << endl;
            return fac;
        }

        int convertInt(vector<int> &v) {
            int ans = 0;
            for (int i : v) {
                ans = ans * 10 + i;
            }

            return ans;
        }
};