#include "../Debug.h"

using namespace std;

/* dump bruteforce O(n!) 
 * list all the permutations
 * sort them, then find the next
 * */


/* smart bruteforce O(n^2) */
vector<int> NextPermutationBruteForce(const vector<int>& A) {
    vector<int> result(A);
    bool has_next = false;
    int i, j;

    if (A.size() == 1 || A.empty()) {
        return result;
    }

    for (i = A.size() - 1; i >= 0 && !has_next; --i) {
        for (j = i; j >= 0 && !has_next; --j) {
            if (A[i] > A[j]) {
                has_next = true;
                swap(result[i], result[j]);
            }
        }
    }

    reverse(result.begin() + j + 2, result.end());

    return result;
}
 
vector<int> NextPermutationSmart(const vector<int>& A) {
    vector<int> result(A);

    /* edge cases */
    if (A.size() == 1 || A.empty()) {
        return result;
    }

    /* first find the starting index longest increasing suffix say j */ 
    int i = A.size() - 1;
    while (i > 0 && A[i] < A[i - 1]) {
        --i;
    }

    /* if the suffix start from 0, then there is not next */
    if (i == 0) {
        return result;
    }

    /* find the element in the surfix that is just greater than A[j - 1] 
     * swap those two elements
     * */
    int j = A.size() - 1;
    while ( (j < i) && (A[j] >= A[i - 1]) ) {
        --j;
    }
    swap(result[j], result[i - 1]);

    /* sort the suffix by reversing it, since it is already sorted in asecending order*/
    reverse(result.begin() + i, result.end());

    return result;
}


int main(void) {
    vector<int> A = { 1, 2, 3, 9, 8, 7, 6, 5, 4 };
    print_vector(NextPermutationSmart(A));

    return 0;
}
