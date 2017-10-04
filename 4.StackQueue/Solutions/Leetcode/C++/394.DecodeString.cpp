#include "../Debug.h"
using namespace std;

string RepeatString(const string& s, int n) {
    string ret;
    for (int i = 0; i < n; i++) {
        ret += s;
    }

    return ret;
}

string DecodeString(string& str ) {
    struct EncodedString {
        int repeat;
        string str;
    };

    vector<EncodedString> string_stack;
    string num_repeat;

    string_stack.emplace_back(EncodedString{1, ""});

    for (size_t i = 0; i < str.size(); i++) {

        if (isdigit(str[i])) {

            num_repeat += str[i];

        } else if (str[i] == '[') {
            string_stack.emplace_back( EncodedString{stoi(num_repeat), ""} );
            num_repeat.clear();

        } else if (str[i] == ']') {

            EncodedString& temp = string_stack.back();
            string expanded = RepeatString(temp.str, temp.repeat);
            string_stack.pop_back();
            string_stack.back().str += expanded;

        } else {

            string_stack.back().str += str[i];

        }
    }

    string ret;
    for (auto estr : string_stack) {
        ret += RepeatString(estr.str, estr.repeat);
    }

    return ret;
}

int main() {

    string s = "3[a2[c]]";
    std::cout << DecodeString(s) << std::endl;

    return 0;
}
