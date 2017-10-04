#include "../Debug.h"
using namespace std;

vector<int> TwoSumII(vector<int>& A, int target) {
    int begin = 0, end = A.size() - 1;
    vector<int> result = { -1, -1 };
    while (begin < end) {
        int sum = A[begin] + A[end];
        if (sum > target) {
            --end;
        } else if (sum < target) {
            ++begin;
        } else {
            break;
        }
    }

    result[0] = begin + 1, result[1] = end + 1;

    return result;
}


