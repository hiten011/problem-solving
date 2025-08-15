// personal files
#include "week2/SquareOfDigits/SquareOfDigits.hpp"
#include "week2/EggCartons/EggCartons.hpp"
#include "week2/ElevatorLimit/ElevatorLimit.hpp"
#include "week2/ChristmasTree/ChristmasTree.hpp"

int main()
{
    SquareOfDigits c1;
    cout << c1.getMax({"9785409507",
                       "2055103694",
                       "0861396761",
                       "3073207669",
                       "1233049493",
                       "2300248968",
                       "9769239548",
                       "7984130001",
                       "1670020095",
                       "8894239889",
                       "4053971072"})
         << endl;

    EggCartons c2;
    cout << c2.minCartons(15) << endl;

    ElevatorLimit c3;
    vector<int> ans = c3.getRange(
        {6, 85, 106, 1, 199, 76, 162, 141}, {38, 68, 62, 83, 170, 12, 61, 114}, 668);
    cout << ans[0] << " " << ans[1] << endl;

    ChristmasTree c4;
    cout << c4.decorationWays(2, 1, 1, 1) << endl;
    return 0;
}