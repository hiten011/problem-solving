// personal files
#include "crazyRobot.hpp"

int main() {
    CrazyRobot c2;
    printf("%0.20f\n", c2.getProb(1, 0.25, 0.25, 0.25, 0.25));
    printf("%0.20f\n", c2.getProb(2, 0.25, 0.25, 0.25, 0.25));
    printf("%0.20f\n", c2.getProb(7, 0.5, 0, 0, 0.5));
    printf("%0.20f\n", c2.getProb(14, 0.5, 0.5, 0, 0));
    printf("%0.20f\n", c2.getProb(14, 0.25, 0.25, 0.25, 0.25));
    return 0;
}