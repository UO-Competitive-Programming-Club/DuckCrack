#include "../Debug.h"
using namespace std;

int ExcelDecoding(const string& s) {

    int figure = 1, result = 0;
    for (size_t i = 0; i < s.size(); i++) {
        result += figure * (s[i] - 'A' + 1);
        figure *= 26;
    }

    return result;

}
