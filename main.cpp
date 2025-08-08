// personal files
#include "week1/Inchworm/Inchworm.hpp"
#include "week1/ThrowTheBall/ThrowTheBall.hpp"
#include "week1/StreetParking/StreetParking.hpp"
#include "week1/CircularLine/CircularLine.hpp"
#include "week1/PartySeats/PartySeats.hpp"

int main() {
    Inchworm c1;
    cout << c1.lunchtime(11, 2, 4) << endl;

    ThrowTheBall c2;
    cout << c2.timesThrown(5, 3, 2) << endl;

    StreetParking c3;
    cout << c3.freeParks("SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D") << endl;

    CircularLine c4;
    cout << c4.longestTravel({1,4,4,1,5}) << endl;

    PartySeats c5;
    c5.seating({"BOB boy","SUZIE girl"});

    return 0;
}