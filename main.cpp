// personal files
#include "week8/FillBox/FillBox.hpp"
#include "week8/CorporationSalary/CorporationSalary.hpp"

int main() {
    FillBox c1;
    cout << c1.minCubes(37, 42, 11, {1100}) << endl;

    CorporationSalary c2;
    cout << c2.totalSalary({"NNYN",
                            "NNYN",
                            "NNNN",
                            "NYYN"})
         << endl;
    return 0;
}