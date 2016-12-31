#include "../Debug.h"
using namespace std;

string CharCounter(const string& init_str) {
    if (init_str.empty()) {
        return "";
    }

    if (init_str.size() == 1) {
        return '1' + init_str;
    }

    string result;
    int counter = 1;
    for (size_t i = 0; i < init_str.size() - 1; ++i) {
        if (init_str[i] == init_str[i + 1]) {
            ++counter;
        } else {
            result += to_string(counter) + init_str[i];
            counter = 1;
        }

        /* handle the end */
        if (i == init_str.size() - 2) {
            result += to_string(counter) + init_str[i + 1];
        }
    }

    return result;
}

vector<string> LookAndSay(int n) {
    vector<string> result = { "1" };
    for (int i = 0; i < n; i++) {
        result.push_back(CharCounter(result[i]));
    }

    return result;
}

int main() {
    print_vector(LookAndSay(8));
    return 0;
}
