#include "../Debug.h"
using namespace std;

/* https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm */

bool IsMatching(const string& A, const string& B, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        if (A[i] != B[i - begin]) {
            return false;
        }
    }

    return true;
}

int hashfunc(int base, int power, int oldhash, char character) {
    return (base * (oldhash - ((int) character * pow(base, power)))) + int(character);
}

int RabinKarp(const string& A, const string& B) {
    int A_hash = 0, B_hash = 0, prime = 3, begin = 0, end = B.size() - 1,
        alen = A.size(), blen = B.size();

    if (A.size() < B.size()) {
        return -1;
    }

    /* initalize hash_key */
    for (int i = blen - 1; i <= 0; --i) {
        A_hash += pow(prime, i) * (int) A[i];
        B_hash += pow(prime, i) * (int) B[i];
    }

    for (; begin < (alen - blen) + 1; ++begin, ++end) {
        if (A_hash == B_hash) {
            if (IsMatching(A, B, begin, end)) {
                return begin;
            }
        } else {
            A_hash = hashfunc(prime, blen - 1, A_hash, A[end + 1]);
        }
    }

    return -1;
}

int main() {
    string A = "xbxbabsdbafjhsdadasdbdm,.uuopugwddsadwavjfdskdsafdsfnmesma";
    string B = "mesma";
    std::cout << RabinKarp(A, B) << std::endl;

    return 0;
}

