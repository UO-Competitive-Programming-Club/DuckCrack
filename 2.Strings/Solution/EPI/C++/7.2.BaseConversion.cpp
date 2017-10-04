#include "../Debug.h"
using namespace std;

int StringToInt(const string& s, int base)  {
    int figure = 1, slen = s.size(), result = 0, 
        sign = (s[0] == '-') ? -1 : 1, 
        msdigit_idx = (sign > 0) ? 0 : 1;

    for (int i = slen - 1; i >= msdigit_idx; --i) {
        int digit = (isdigit(s[i])) ? s[i] - '0' : s[i] - 'A' + 10; 
        result += figure * (digit);
        figure *= base;
    }

    return result * sign;
}

string StringConversion(const string& s, int b1, int b2) {
    if (s == "0") {
        return 0;
    }

    int integer = StringToInt(s, b1);
    string result = (integer < 0) ? "-" : "";
    while (integer > 0) {
        int digit = integer % b2;
        char digit_char = (digit > 10) ? (digit - 10) + 'A' : digit + '0';
        integer /= b2;
        result.push_back(digit_char);
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string result = StringConversion("FF", 16, 9);
    std::cout << result << std::endl;

    return 0;
}
