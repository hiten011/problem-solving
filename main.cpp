// personal files
#include "crazyRobot.hpp"
#include "week3/FewestFactors/FewestFactors.hpp"
#include "week3/QuickSums/QuickSums.hpp"
#include "week3/SimpleCompressor/SimpleCompressor.hpp"

int main() {
    CrazyRobot c2;
    printf("%0.20f\n", c2.getProb(1, 0.25, 0.25, 0.25, 0.25));
    // printf("%0.20f\n", c2.getProb(2, 0.25, 0.25, 0.25, 0.25));
    // printf("%0.20f\n", c2.getProb(7, 0.5, 0, 0, 0.5));
    // printf("%0.20f\n", c2.getProb(14, 0.5, 0.5, 0, 0));
    // printf("%0.20f\n", c2.getProb(14, 0.25, 0.25, 0.25, 0.25));

    FewestFactors c1;
    cout << c1.number({7, 5, 4, 3, 6}) << endl;

    QuickSums c3;
    cout << c3.minSums("9230560001", 71) << endl;

    SimpleCompressor c4;
    cout << c4.uncompress("C[6AB]C") << endl;
    return 0;
}