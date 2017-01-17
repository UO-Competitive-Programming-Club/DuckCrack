#include "../Debug.h"
using namespace std;

bool HasDuplicateParenthesis(string & str) {
    stack<char> S;
    int strlen = str.size();

    for (int i = 0; i < strlen; i++) {
        if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {

            S.emplace(str[i]);

        } else if (str[i] == ')') {

            int counter = 0;
            while (!S.empty() && S.top() != '(') {
                S.pop();
                ++counter;
            }

            /* pop the '(' */
            if (!S.empty()) {
                S.pop();
            }

            if (counter == 0) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    // input balanced expression
    string str = "( ( a + b ) + (( c + b )) )";
 
    if (HasDuplicateParenthesis(str))
        cout << "Duplicate Found " << endl;
    else
        cout << "No Duplicates Found " << endl;
 
    return 0;
}
