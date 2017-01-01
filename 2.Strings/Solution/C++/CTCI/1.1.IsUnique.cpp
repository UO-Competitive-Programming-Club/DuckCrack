#include "../Debug.h"
using namespace std;

/* we use the fact that the whole asscii table has only 256 entries, so the */
/* space is constant */
bool IsUnique(const string& s) {
    vector<int> ascii_table(256, 0);
    for (size_t i = 0; i < s.size(); i++) {
        if (!ascii_table[ (int) s[i] ]) {
            return false;
        }

        ++ascii_table[ (int) s[i] ];

    }

    return true;
}
