#include "../Debug.h"
using namespace std;

void printSinWave(const string & s) {
    int slen = static_cast<int>(s.size());
    string space2 = "  ", space3 = "   ", space6 = "      ", space7 = "       ";

    std::cout << space2;
    for (int j = 1; j < slen; j += 4) {
        std::cout << s[j] << space7;
    }

    std::cout << std::endl;

    for (int i = 0; i < slen; i += 2) {
        std::cout << s[i] << space3;
    }

    std::cout << std::endl;

    std::cout << space6;
    for ( int k = 3; k < slen; k += 4) {
        std::cout << s[k] << space7;
    }

    std::cout << std::endl;
}
