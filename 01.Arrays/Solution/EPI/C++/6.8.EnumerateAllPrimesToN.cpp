#include "../Debug.h"

using namespace std;

/* brute force solution check if the current number of 
 * a multiple of primes*/
vector<int> AllPrimes(int n) {
    vector<int> primes = {1, 2}; 
    if (n == 0) { return vector<int>{ }; }
    if (n == 1) { return vector<int>{ 1 }; }
    if (n == 2) { return primes; }

    for (int i = 3; i < n; ++i) {
        bool is_prime = true;

        for (auto& prime: primes) {
            if ( i % prime == 0 ) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            primes.push_back(i);
        }
    }

    return primes;
}

/* smart solution */
vector<int> AllPrimesMemorized(int n) {
    vector<bool> T(n, true);
    vector<int> primes = { 1 };

    /* edge cases */
    if (n == 0) { return vector<int>{ }; }
    if (n == 1) { return primes; }

    /* base case 1 and 2 are primes*/
    for (int i = 2; i < n; i++) {
        if (T[i]) {
            primes.push_back(i);
            for (int j = 1; i * j < n; ++j) {
                T[i * j] = false;
            }
        }
    }

    return primes;
}

int main() {
    print_vector(AllPrimesMemorized(100));
}
