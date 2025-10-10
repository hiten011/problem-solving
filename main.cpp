// personal files
#include "week8/FillBox/FillBox.hpp"
#include "week8/CorporationSalary/CorporationSalary.hpp"
#include "week8/ProblemsToSolve/ProblemsToSolve.hpp"

int main() {
    FillBox c1;
    cout << c1.minCubes(37, 42, 11, {1100}) << endl;

    CorporationSalary c2;
    cout << c2.totalSalary({"NNYN",
                            "NNYN",
                            "NNNN",
                            "NYYN"})
         << endl;

    ProblemsToSolve c3;
    cout << c3.minNumber({1, 2, 3}, 2) << endl;
    return 0;
}