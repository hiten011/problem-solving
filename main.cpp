// personal files
#include "week1/Inchworm/Inchworm.hpp"
#include "week1/ThrowTheBall/ThrowTheBall.hpp"
#include "week1/StreetParking/Streetparking.hpp"

int main() {
    Inchworm c1;
    cout << c1.lunchtime(11, 2, 4) << endl;

    ThrowTheBall c2;
    cout << c2.timesThrown(5, 3, 2) << endl;

    StreetParking c3;
    cout << c3.freeParks("DDBDDBDDBDD"
) << endl;

    return 0;
}