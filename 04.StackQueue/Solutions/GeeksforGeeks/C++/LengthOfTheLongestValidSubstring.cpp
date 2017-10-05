#include "../Debug.h"

using namespace std;

int LongestValidSubstring(const string& str) {
    stack<int> S;
    int result = 0, slen = str.size();
    for (int i = 0; i < slen; i++) {
        if (str[i] == '(') {
            S.emplace(i);
        } else {
            S.pop();
            if (!S.empty()) { 
                result = max(result, (i - S.top()));
            } else {
                S.push(1);
            }
        }
    }

    return result;
}
