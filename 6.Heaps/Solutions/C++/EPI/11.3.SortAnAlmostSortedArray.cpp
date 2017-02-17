#include "../Debug.h"
using namespace std;

void SortApproximatelySortedData(istringstream* sequence, int k) {
    priority_queue<int, vector<int>, greater<>> min_heap;

    int x;
    for (int i = 0; i < k && *sequence >> x; i++) {
        min_heap.emplace(x);
    }

    while (*sequence >> x) {
        min_heap.emplace(x);
        std::cout <<  min_heap.top() << std::endl;
        min_heap.pop();
    }

    while (!min_heap.empty()) {
        std::cout << min_heap.top() << std::endl;
        min_heap.top();
    }
}
