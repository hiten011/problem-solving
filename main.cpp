// personal files
#include "week1/Inchworm/Inchworm.hpp"
#include "week1/ThrowTheBall/ThrowTheBall.hpp"
#include "week1/StreetParking/StreetParking.hpp"
#include "week1/CircularLine/CircularLine.hpp"
#include "week1/PartySeats/PartySeats.hpp"

int main() {
    Inchworm c1;
    cout << c1.lunchtime(11, 2, 4) << endl; // O(logN)

    ThrowTheBall c2;
    cout << c2.timesThrown(5, 3, 2) << endl; // O(M*N)

    StreetParking c3;
    cout << c3.freeParks("SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D") << endl; // O(N)

    CircularLine c4;
    cout << c4.longestTravel({1,1,1,1,4}) << endl; // O(N)

    PartySeats c5;
    c5.seating({"BOB boy", "SUZIE girl", "DAVE boy", "JO girl", "AL boy", "BOB boy", "CARLA girl", "DEBBIE girl"}); // O(N + (N/2)log(N/2)): O(NlogN)

    return 0;
}