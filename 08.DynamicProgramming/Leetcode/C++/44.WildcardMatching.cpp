#include <iostream>
#include <vector>

using namespace std;


bool isMatch(string s, string p) {
    int slen = s.size(), plen = p.size();
    vector<vector<int> > memo(slen + 1, vector<int>(plen + 1, false));
    memo[0][0] = true;

    for (int j = 1; j <= plen; j++) {
        char s_first_char = s.front();
        if (p[j - 1] == '*' && memo[0][j - 1]) {
            memo[0][j] = true;
        }
    }

    for (int i = 1; i <= slen; i++) {
        for (int j = 1; j <= plen; j++) {
            bool are_cur_letters_match = (memo[i - 1][j - 1]) && 
                                         ((p[j - 1] == '?') || (s[i - 1] == p[j - 1])),
                 
            is_wildcard_match = (memo[i - 1][j] || memo[i][j - 1]) && (p[j - 1] == '*');
            memo[i][j] = are_cur_letters_match || is_wildcard_match;
        }
    }

    return memo[slen][plen];
}

int main() {
    cout << isMatch("aaaaaaa", "*a") << endl;
    return 0;
}
