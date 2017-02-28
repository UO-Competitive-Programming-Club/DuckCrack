#include "../Debug.h"

using namespace std;

int nthUglyNumber(int n) {
    if (n <= 1) {
        return 1;
    }

    priority_queue<int, vector<int>, greater<>> min_heap;
    min_heap.emplace(2);
    min_heap.emplace(3);
    min_heap.emplace(5);

    for (int i = 2; i < n; i++) {
       int min = min_heap.top();
       min_heap.pop();

       min_heap.emplace(min * 2);
       min_heap.emplace(min * 3);
       min_heap.emplace(min * 5);
    }     

    return min_heap.top();
}




