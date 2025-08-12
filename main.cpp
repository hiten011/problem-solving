// personal files
#include "week2/SquareOfDigits/SquareOfDigits.hpp"
#include "week2/EggCartons/EggCartons.hpp"

int main() {
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
    return 0;
}