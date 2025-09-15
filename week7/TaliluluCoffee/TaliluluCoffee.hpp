#include <bits/stdc++.h>
using namespace std;

class TaliluluCoffee
{
public:
    	int maxTip(vector<int> tips) {
            sort(tips.begin(), tips.end(), greater<int>()); 

            int ans = 0;
            for (int i = 0; i < tips.size(); i++) {
                if (tips[i] - i < 0) break;

                ans += tips[i] - i;
            }

            return ans;
        }
private:
};
