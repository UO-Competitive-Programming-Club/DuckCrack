#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <limits>
#include <climits>
#include <queue>
#include <stack>
#include <memory>
#include <algorithm>
#include <random>
#include <sstream>

template <typename T>
void print_vector(const std::vector<T>& A) {
    if (A.empty()) {
        std::cout << "empty vector" << std::endl;
    } else {
        std::cout << "[ ";
        for (size_t i = 0; i < A.size(); ++i) {
            std::cout << A[i];
            if (i != A.size() - 1) {
                std::cout << ", ";
            }
        }

        std::cout << " ]" << std::endl;
    }
}

template <typename T>
void print_matrix(const std::vector<std::vector<T>>& matrix) { 
    int height = matrix.size();
    for (int i = 0; i < height; i++) {
         print_vector(matrix[i]);
    }
}

#endif
