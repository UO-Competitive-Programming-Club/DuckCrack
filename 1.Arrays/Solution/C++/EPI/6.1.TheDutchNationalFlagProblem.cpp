#include "../Debug.h"

using namespace std;

void DutchNationalFlag(int pivot, vector<int>& A) {
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


/* variant */
void SortArrayOfTwoValues(int low_val, vector<int>& A) {
    int low = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] > low_val) {
            swap(A[low++], A[i]);
        }
    }
}


/* variant */
void GroupFourValues(vector<int>& A) { 
    int low = 0, mid = 0, high = A.size() - 1, pivot = 1;
    /* do the groupping twice, */ 

    /* first grouping we treat the third and fourth biggest elements */ 
    /* the same element and move them to the end of the array */
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

    /* second grouping we regroup the third and fourth biggest elements */  
    low = mid;
    for (size_t i = mid; i < A.size(); ++i) {
        if (A[i] < 3) {
            swap(A[low++], A[i]);
        }
    }
}

int main(void) {
    vector<int> A = { 3, 1, 0, 1, 3, 1, 2, 2, 1, 1, 0, 3, 0, 3, 1, 0, 1 };
    vector<int> A2 = { 1, 0, 2, 3};
    GroupFourValues(A2);
    print_vector(A2);

    return 0;
}
