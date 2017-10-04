#include "../Debug.h"
using namespace std;

vector<int> Multiply(vector<int>& A, vector<int>& B) {
    int lenA = A.size(), lenB = B.size(), reslen = lenA + lenB ;
    vector<int> result(reslen, 0);

    int sign = ( (A.front() > 0) ^ (B.front() > 0) ) ? -1 : 1;

    A.front() = abs(A.front()), B.front() = abs(B.front());

    for (int i = lenA - 1; i >= 0; --i) {
        for (int j = lenB - 1; j >= 0; --j) {
            /* accumulate the result into the current position */
            result[i + j + 1] += A[i] * B[j];

            /* check if there is carry */
            int carry = result[i + j + 1] / 10;

            /* if carry exsit, we accumulate that to the next position */
            result[i + j] += carry;

            /* caculate the current digit for current position */
            result[i + j + 1] %= 10;
        }
    }     
        
    if (result.front() == 0) {
        result.erase(result.begin());
    }

    result.front() *= sign;

    return result;
}

int main() {
    vector<int> A = {1,9,9,9,9,9,9,9};
    vector<int> B = {-1,1};
        
    print_vector(Multiply(A, B));

    return 0;
}
