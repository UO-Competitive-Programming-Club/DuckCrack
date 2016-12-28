#include "../Debug.h"
using namespace std; 

int FourSumCount(const vector<int>& A, 
                 const vector<int>& B, 
                 const vector<int>& C, 
                 const vector<int>& D) {

    unordered_map<int, int> AB_sum_map,
                            CD_sum_map;

    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < B.size(); j++) {
            int AB_sum = A[i] + B[j];
            (AB_sum_map.find(AB_sum) != AB_sum_map.end()) ?
                ++AB_sum_map[AB_sum] :
                AB_sum_map[AB_sum] = 1;
        }
    }

     
    for (size_t i = 0; i < C.size(); i++) {
        for (size_t j = 0; j < D.size(); j++) {
            int CD_sum = C[i] + D[j];

            (CD_sum_map.find(CD_sum) != CD_sum_map.end()) ?
                ++CD_sum_map[CD_sum] :
                CD_sum_map[CD_sum] = 1;
        }
    }

    int count = 0;
    for (auto AB_sum_count: AB_sum_map) {
        int AB_sum = AB_sum_count.first;
        if (CD_sum_map.find(-AB_sum) != CD_sum_map.end()) {
            count += CD_sum_map[-AB_sum] * AB_sum_count.second;
        }
    }

    return count;
}

