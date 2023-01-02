#include <iostream>
#include "FuzzyMatch.h"
#include "LevenshteinDistance.h"

using namespace std;

int main()
{
    /*std::cout << "Hello World!\n";*/
    std::cout << fuzzyMatch("kitten", "sitting", 0.6) << std::endl;
    std::cout << fuzzyMatch("flaw", "flaws", 0.6) << std::endl;
    std::cout << fuzzyMatch("abc", "abd", 0.7) << std::endl;

}


