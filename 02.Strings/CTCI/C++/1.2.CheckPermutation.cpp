#include "../Debug.h"
using namespace std;

bool IsPermuation(const string& A, const string& B) {
    if (A.size() != B.size()) {
        return false;
    }

    vector<int> ascii_count(256, 0);

    for (size_t i = 0; i < A.size(); i++) {
        ++ascii_count[(int) A[i]];
        --ascii_count[(int) B[i]];
    }

    for (size_t i = 0; i < 256; i++) {
        if (ascii_count[i] != 0) {
            return false;
        }
    }

    return true;
}
