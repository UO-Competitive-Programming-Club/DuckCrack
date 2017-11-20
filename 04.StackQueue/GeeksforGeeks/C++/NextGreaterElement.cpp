#include "../Debug.h"
using namespace std;

vector<int> NextGreaterElement(const vector<int>& A) {
    stack<int> S;
    vector<int> result(A.size(), -1);
    S.emplace(0);

    for (size_t next = 1; next < A.size(); next++) {
        while (!S.empty() && (A[S.top()] < A[next])) {
            result[S.top()] = A[next];
            S.pop();
        }

        S.emplace(next);
    }

    return result;
}


int main() {
    vector<int> A = {2,5,3,1,0,5,2,4,6,3,1,23,123,456,2,1};
    PrintVector(A);
    PrintVector(NextGreaterElement(A));

    return 0;
}
