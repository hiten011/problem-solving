// personal files
#include "week7/ShipBoxes/ShipBoxes.hpp"
#include "week7/PrefixFreeSets/PrefixFreeSets.hpp"

int main() {
    ShipBoxes c1;
    cout << c1.bestCost({314, 159, 262},

                        {271, 818, 282})
         << endl;

    PrefixFreeSets c2;
    cout << c2.maxElements({"hello", "hi", "h", "run", "rerun", "running"}) << endl;
    return 0;
}