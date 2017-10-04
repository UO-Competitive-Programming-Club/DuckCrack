#include "../Debug.h"
using namespace std;

string IntToString(int num) {
    string result = (num < 0) ? "-" : "";
    num = abs(num);
    int num_digits = 0, base, temp = num;

    /* first count how many digits it has */
    while (temp > 0) {
        temp /= 10;
        ++num_digits;
    }

    base = pow(10, num_digits - 1);;

    /* then we build it digit by digit */
    for (int i = 0; i < num_digits; i++) {
        int digit = num / base;
        num -= digit * base;
        base /= 10;
        result.push_back(digit + '0');
    }

    return result;
}


int StringToInt(const string& s)  {
    int base = 1, slen = s.size(), result = 0, 
        sign = (s[0] == '-') ? -1 : 1, 
        msdigit_idx = (sign > 0) ? 0 : 1;

    for (int i = slen - 1; i >= msdigit_idx; --i) {
        result += base * (s[i] - '0');
        base *= 10;
    }

    return result * sign;
}

int main() {
    string result = IntToString(-12345);
    std::cout << result << std::endl;
    return 0;
}

