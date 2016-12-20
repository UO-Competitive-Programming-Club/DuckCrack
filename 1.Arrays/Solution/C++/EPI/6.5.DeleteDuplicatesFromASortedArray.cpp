#include "../Debug.h"
using namespace std;
int RemoveDuplicates(vector<int>& A) {
    if (A.empty()) {
        return 0;
    }

    int write_index = 1;
    for (size_t i = 0; i < A.size(); i++) {
        if (A[write_index - 1] != A[i]) {
            A[write_index++] = A[i];
        }
    }

    return write_index;
}


int main() {
    vector<int> A = {1,2,2,2,2,2,2,2,2,2,2,2,2,3,4,4,4,5,5,5,6,6,6,7,7,7,8,9,10};
    RemoveDuplicates(A);

    print_vector(A);

    return 0;
}
