#include "../Debug.h"
using namespace std;

/* just added another for loop outside, plus a check of duplicate */ 
vector<vector<int>> FourSum(vector<int>& A, int target) {
    sort(A.begin(), A.end());
    int alen = A.size();
    vector<vector<int>> result;
    
    for (int j = 0; j < alen - 3; j++) {
        if (j > 0 && A[j] == A[j - 1]) {
            continue;
        }

        for (int i = j + 1; i < alen - 2; i++) {
            if (i > 1 + j && A[i] == A[i - 1]) {
                continue;
            }

            int begin = i + 1, end = alen - 1;

            while (begin < end) {
                int sum = A[i] + A[j] + A[begin] + A[end];

                if (sum < target) {
                    ++begin;

                } else if (sum > target) {
                    --end;

                } else {
                    result.emplace_back( vector<int> {A[j], A[i], A[begin], A[end] } );
                    int begin_next = begin + 1, end_next = end - 1;

                    while (begin_next < end && A[begin] == A[begin_next]) { ++begin_next; }
                    while (begin < end_next && A[end] == A[end_next]) { --end_next; }

                    begin = begin_next, end = end_next;
                }
            }

            /* while (i < alen - 2 && A[i] == A[i + 1]) { ++i; } */
        }
    }

    return result;
}

int main() {
    vector<int> A = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = FourSum(A, -1);
    print_matrix(result);
    return 0;
}
