#include "../Debug.h"
using namespace std;

vector<int> computeLPSArray(const string& s) {
    // jth of the previous longest prefix suffix
    int j = 0, slen = s.size();
    vector<int> lps(s.size(), 0);
 
    int i = 1;
    while (i < slen) {
        if (s[i] == s[j]) {

            j++, lps[i] = j, i++;

        } else { // (s[i] != s[j]) 
            if (j != 0) {

                j = lps[j-1];
            } else { // if (j == 0)

                lps[i] = 0;
                i++;

            }
        }
    }

    return lps;
}

int GetMinCharToAddedToMakeStringPalin(string str) {
    string reversed = str;
    reverse(str.begin(), str.end());
    string cat = str + "*" + reversed;;
    vector<int> lps = computeLPSArray(cat);
    return (str.length() - lps.back());
}
