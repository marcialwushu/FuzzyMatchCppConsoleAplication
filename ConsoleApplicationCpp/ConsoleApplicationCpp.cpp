
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include "FuzzyMatch.h"
#include "LevenshteinDistance.h"

int min3(int a, int b, int c) {
    return std::min(a, std::min(b, c));
}

int levenshteinDistance(std::string str1, std::string str2) {
    int n = str1.size();
    int m = str2.size();

    std::vector<std::vector<int>> d(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        d[0][j] = j;
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (str1[i - 1] == str2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            }
            else {
                d[i][j] = min3(
                    d[i - 1][j] + 1,
                    d[i][j - 1] + 1,
                    d[i - 1][j - 1] + 1
                );
            }
        }
    }

    return d[n][m];
}


int fuzzyMatch(std::string pattern, std::string target, double maxRatio) {
    int distance = levenshteinDistance(pattern, target);
    int m = pattern.size();
    int n = target.size();
    int maxLength = std::max(m, n);
    double ratio = 1.0 - (double)distance / maxLength;
    if (ratio < maxRatio) {
        return (int)(ratio * 100);
    }
    else {
        return 0;
    }
}


//
//int main()
//{
//    
//    std::cout << fuzzyMatch("kitten", "sitting", 0.6) << std::endl;
//    std::cout << fuzzyMatch("flaw", "flaws", 0.6) << std::endl;
//    std::cout << fuzzyMatch("abc", "abd", 0.7) << std::endl;
//
//}
