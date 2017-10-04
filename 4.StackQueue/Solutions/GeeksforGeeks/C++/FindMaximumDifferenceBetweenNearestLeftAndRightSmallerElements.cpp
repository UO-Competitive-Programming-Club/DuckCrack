#include "../Debug.h"
using namespace std;

vector<int> NearestRightSmaller(const vector<int>& A) {
    stack<int> S;
    vector<int> nrs(A.size(), 0);
    S.emplace(0);
    for (size_t next = 1; next < A.size(); next++) {
        while (!S.empty() && A[S.top()] > A[next]) {
            nrs[S.top()] = A[next];
            S.pop();
        }

        S.emplace(next);
    }

    return nrs;
}

vector<int> NearestLeftSmaller(const vector<int>& A) {
    stack<int> S;
    vector<int> nls(A.size(), 0);
    S.emplace(A.size() - 1);
    for (int next = A.size() - 2; next >= 0; --next) {
        while (!S.empty() && A[S.top()] > A[next]) {
            nls[S.top()] = A[next];
            S.pop();
        }

        S.emplace(next);
    }

    return nls;
}

int FindMaxDifference(const vector<int>& A) {
    vector<int> nls = NearestLeftSmaller(A),
                nrs = NearestRightSmaller(A);

    int result = -1;
    for (size_t i = 0; i < A.size(); i++) {
        result = max(result, abs(nls[i] - nrs[i]));
    }
    
    return result;
}

int main() {
    vector<int> A = {2, 4, 8, 7, 7, 9, 3};
    cout << FindMaxDifference(A) << endl;
    return 0;
}





