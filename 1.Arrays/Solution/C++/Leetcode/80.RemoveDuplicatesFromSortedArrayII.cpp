#include "../Debug.h"

using namespace std; 

int RemoveDuplicatesII(vector<int>& A) {
    int i = 0;
    for (int n : A) {
        if (i < 2 || n > A[i - 2]) {
            A[i++] = n;
        }

    }

    return i;
}

int main(void) {
    vector<int> A = { 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 6, 7, 8};
    print_vector(A);
    RemoveDuplicatesII(A);
    print_vector(A);

    return 0;
}
