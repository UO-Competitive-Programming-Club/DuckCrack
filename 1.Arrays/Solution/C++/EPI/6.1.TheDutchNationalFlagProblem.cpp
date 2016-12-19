#include "../Debug.h"

using namespace std;

void SortFlags(int pivot, vector<int>& A) {
    int low = 0, mid = 0, high = A.size() - 1;
    /* the range between mid and high are unsorted */

    while (mid <= high) {
        if (A[mid] < pivot) {
            /* we increment low and mid, because we already know that between 0 - low and */ 
            /* low - mid are already sorted */
            swap(A[low++], A[mid++]);
        } else if (A[mid] == pivot) {
            ++mid;
        } else {
            /* here we don't increment mid because the range from mid - hi are not sorted */
            swap(A[high--], A[mid]);
        }
    }

}
