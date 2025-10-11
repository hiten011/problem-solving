// personal files
#include "week9/ErdosNumber/ErdosNumber.hpp"
#include "week9/SentenceDecomposition/SentenceDecomposition.hpp"

int main() {
    ErdosNumber c1;
    c1.calculateNumbers({"ERDOS B", "A B C", "B A E", "D F"});

    SentenceDecomposition c2;
    cout << c2.decompose("ommwreehisymkiml", {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"}) << endl;

    return 0;
}