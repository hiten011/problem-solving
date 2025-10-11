// personal files
#include "week9/ErdosNumber/ErdosNumber.hpp"
#include "week9/SentenceDecomposition/SentenceDecomposition.hpp"
#include "week9/RoughStrings/RoughStrings.hpp"

int main() {
    ErdosNumber c1;
    c1.calculateNumbers({"ERDOS B", "A B C", "B A E", "D F"});

    SentenceDecomposition c2;
    cout << c2.decompose("ommwreehisymkiml", {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"}) << endl;

    RoughString c3;
    cout << c3.minRoughness("aaaaabbc", 1) << endl;

    return 0;
}