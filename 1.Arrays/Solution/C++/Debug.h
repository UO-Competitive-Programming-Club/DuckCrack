#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <iostream>
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

template <typename T>
void print_vector(const std::vector<T>& A) {
    if (A.empty()) {
        std::cout << "empty vector" << std::endl;
    } else {
        std::cout << "[ ";
        for (auto n: A) {
            std::cout << n << ", ";
        }

        std::cout << "]" << std::endl;
    }
}


#endif
