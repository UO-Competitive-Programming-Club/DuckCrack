#include "../Debug.h"
using namespace std;

string RemoveKdigits(string num, int k) {
    vector<char> digit_stack;
    num += '0' - 1;
    for (size_t i = 0; i < num.size(); i++) {
        while (!digit_stack.empty() && digit_stack.back() > num[i] && k > 0) {
            digit_stack.pop_back();
            --k;
        }

        digit_stack.emplace_back(num[i]);
    }


    auto nonzero_begin = find_if(digit_stack.begin(), digit_stack.end(), 
            [](const char d) {return d != '0';});

    string ret;

    for (auto iter = nonzero_begin; iter != digit_stack.end() - 1; iter++) {
        ret += *iter;
    }

    return ((ret.empty()) ? "0" : ret);

}

int main() {
    string s = "112";
    std::cout << RemoveKdigits(s, 1) << std::endl;

    return 0;

}
