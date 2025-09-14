// personal files
#include "week6/JumpyNum/JumpyNum.hpp"
#include "week6/NiceOrUgly/NiceOrUgly.hpp"
#include "week6/ColorfulRabbits/ColorfulRabbits.hpp"

int main() {
    JumpyNum c1;
    cout << c1.howMany(8000, 20934) << endl;

    NiceOrUgly c2;
    cout << c2.describe("O?ZPB?I?FXR?I?QCL?E?NHJ?O?MQM?O?MWX?E?CYY?A?GCGL") << endl;

    ColorfulRabbits c3;
    cout << c3.getMinimum({1, 1, 2, 2}) << endl;
    return 0;
}