#include "../Debug.h"

using namespace std;

/* bruteforce solution 34sm not too bad*/
bool repeatedSubstringPattern(const string& s) {
    int slen = s.size();
    for (int window = 1; window <= slen / 2; window++) {

        /* it only works if the the slen can be divided by window size 
         * therefore we can optimize it here */
        if (slen % window != 0) {
            continue;
        }

        int matching_window_count = 0, matching_goal = slen / window;
        for (int i = 0; i < slen; i += window) {
            if (s.compare(0, window, s, i, window) == 0) {
                ++matching_window_count;
            }
            if (matching_window_count == matching_goal) {
                return true;
            }
        }
    }

    return false;
}


