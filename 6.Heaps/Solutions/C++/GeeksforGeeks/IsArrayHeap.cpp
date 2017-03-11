#include "../Debug.h"
using namespace std;

bool IsArrayHeap(const vector<int>& A) {
    int alen = A.size();
    for (int i = 0; i <= (alen / 2) + (alen % 2); i++) {
        int left_idx = i * 2,
            right_idx = i * 2 + 1;

        if ( (left_idx < alen && A[left_idx] < A[i]) || 
             (right_idx < alen && A[right_idx] < A[i]) ) {
            return false;
        }
    }

    return true;
}
