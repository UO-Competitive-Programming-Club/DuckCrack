#include "../Debug.h"

using namespace std;

vector<int> FindAllDuplicates(vector<int>& A) {
    int alen = A.size();
    vector<int> result;
    for (int i = 0; i < alen; i++) {
        if (A[abs(A[i]) - 1] > 0) {
           A[abs(A[i]) - 1] = -A[abs(A[i]) - 1];
        } else {
           result.emplace_back(abs(A[i]));
        }
    }

    return result;
}

int main() {
    vector<int> A = {5,4,6,7,9,3,10,9,5,6};
    print_vector(FindAllDuplicates(A));
        
    return 0;
}
