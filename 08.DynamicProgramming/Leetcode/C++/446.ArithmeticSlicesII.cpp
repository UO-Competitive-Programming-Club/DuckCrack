#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
    int alen = A.size();
    vector<unordered_map<int, int>> memo;

    for (int i = 1; i < alen; ++i) {
        for (int j = 0; j < i; ++j) {
            int difference = A[i] - A[j];
        }
    }

}

