#include "../Debug.h"

using namespace std;

int ThreeSum(vector<int>& A, int target) {
    sort(A.begin(), A.end());
    int alen = A.size(), closest_sum = A[0] + A[1] + A[2];

    for (int i = 0; i < alen - 2; i++) {
        if (i > 0 && A[i] == A[i - 1]) {
            continue;
        }

        int begin = i + 1, end = alen - 1;

        while (begin < end) {
            int sum = A[i] + A[begin] + A[end];
            if (abs(sum - target) < abs(closest_sum - target)) {
                closest_sum = sum;
            }

            if (sum < target) {
                ++begin;

            } else if (sum > target) {
                --end;

            } else {
                return target;
            }
        }

        /* while (i < alen - 2 && A[i] == A[i + 1]) { ++i; } */
    }

    return closest_sum;
}

int main() {
    vector<int> A = {-1, 2, 1, -4};
    int result = ThreeSum(A, 1);
    std::cout << result << std::endl;
    return 0;
}
