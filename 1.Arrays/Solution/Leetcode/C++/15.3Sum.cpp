#include "../Debug.h"

using namespace std;

/* this problem is a follow up of 2sum problem, we use the same idea, but first we need to 
 * sort the array */ 

vector<vector<int>> ThreeSum(vector<int>& A) {
    sort(A.begin(), A.end());
    int alen = A.size();
    vector<vector<int>> result;

    for (int i = 0; i < alen - 2; i++) {
        if (i > 0 && A[i] == A[i - 1]) {
            continue;
        }

        int target = -A[i], begin = i + 1, end = alen - 1;

        while (begin < end) {
            int sum = A[begin] + A[end];

            if (sum < target) {
                ++begin;

            } else if (sum > target) {
                --end;

            } else {
                result.emplace_back( vector<int> { A[i], A[begin], A[end] } );
                int begin_next = begin + 1, end_next = end - 1;

                while (begin_next < end && A[begin] == A[begin_next]) { ++begin_next; }
                while (begin < end_next && A[end] == A[end_next]) { --end_next; }

                begin = begin_next, end = end_next;
            }
        }

        /* while (i < alen - 2 && A[i] == A[i + 1]) { ++i; } */
    }

    return result;
}

int main() {
    vector<int> A = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = ThreeSum(A);
    print_matrix(result);
    return 0;
}
