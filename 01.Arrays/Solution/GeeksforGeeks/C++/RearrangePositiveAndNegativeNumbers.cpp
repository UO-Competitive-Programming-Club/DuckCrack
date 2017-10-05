#include "../Debug.h"
using namespace std; 

void RearrangePositiveNegativeNumbers(vector<int>& A) {
    int write_idx = 0, alen = A.size(), next_negative_idx;
    /* sort the array, positive first then negative */
    for (int i = 0; i < alen; i++) {
        if (A[i] > 0) {
            swap(A[write_idx++], A[i]);
        }
    }

    /* after sorting the value in variable write index indicates the position of 
     * the start of negative numbers */

    next_negative_idx = write_idx;
    write_idx = 1;

    while (next_negative_idx != alen && write_idx <= next_negative_idx) {
        swap(A[write_idx], A[next_negative_idx++]);
        write_idx += 2;
    }
}

int main() {
    vector<int> A = {-1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, 1};
    print_vector(A);
    RearrangePositiveNegativeNumbers(A);
    print_vector(A);

    return 0;
}
