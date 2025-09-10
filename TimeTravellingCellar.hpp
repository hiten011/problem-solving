#include <bits/stdc++.h>
using namespace std;

class TimeTravellingCellar
{
public:
    int determineProfit(vector<int> profit, vector<int> decay) {
        int n = profit.size();
        vector<pair<int, int>> pro(n);
        vector<pair<int, int>> dec(n);

        for (int i = 0; i < n; i++) {
            pro[i] = {profit[i], i};
            dec[i] = {decay[i], i};
        }

        sort(pro.begin(), pro.end());
        sort(dec.begin(), dec.end());

        int st = 0, en = n - 1, ans = 0;
        while (st <= en) {
            int curProfit= pro[en].first;
            int idxEn = pro[en].second;
            int curLoss = dec[st].first;
            int idxSt = dec[st].second;

            if (idxSt == idxEn)
            {
                // check both
                int Pdiff = curProfit - pro[en - 1].first;
                int Ddiff = dec[st + 1].first - curLoss;

                if (Pdiff < Ddiff) {
                    en--;
                } else {
                    st++;
                }
            }
            else if (curProfit > curLoss)
            {
                // cout << curProfit << curLoss << endl;
                ans += curProfit;
                ans -= curLoss;
                st++;
                en--;
                break;
            }
            else
            {
                break;
            }
        }

        return ans;
    }

    // AI: CHATGBT
    int determineProfitAI(const vector<int> &profit, const vector<int> &decay)
    {
        int n = profit.size();
        int best = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                best = max(best, profit[i] - decay[j]);
            }
        }
        return best;
    }
};