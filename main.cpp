// personal files
#include "week5/TomekPhone/TomekPhone.hpp"
#include "week5/HouseBuilding/HouseBuilding.hpp"
#include "week5/NumberSplit/NumberSplit.hpp"
#include "week5/RGBStreet/RGBStreet.hpp"

int main() {
    TomekPhone c1;
    cout << c1.minKeystrokes({100, 1000, 1, 10}, {50}) << endl;

    HouseBuilding c2;
    cout << c2.getMinimum({"54454","61551"}) << endl;

    NumberSplit c3;
    cout << c3.longestSequence(876) << endl;

    RGBStreet c4;
    cout << c4.estimateCost({"1 100 100", "100 100 100", "1 100 100"}) << endl;
    return 0;
}