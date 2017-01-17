#include "../Debug.h"
using namespace std;

int MinBrackets(const string& str) {
    int strlen = str.size(), closing_brackets = 0, open_brackets = 0;
    stack<char> S;
    
    for (int i = 0; i < strlen; i++) {
        if (str[i] == '{') {
            S.emplace('{');
        } else {
            if (S.empty() || S.top() == -1) {
                S.emplace('}');
            } else if (!S.empty() && S.top() == 1){
                S.pop();
            }
        }
    }

    while (!S.empty()) {
        if (S.top() == '{') {
            open_brackets++;
        } else {
            closing_brackets++;
        }
    }

    return ceil(open_brackets) / 2 + ceil(closing_brackets) / 2;
}
