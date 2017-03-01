#include "../Debug.h"

using namespace std;


int kthSmallestHeap(vector<vector<int>>& matrix, int k) {
    struct HeapEntry {
        vector<int>::const_iterator iter;
        vector<int>::const_iterator end;
        bool operator>(const HeapEntry& that) const {
            return *(this->iter) > *(that.iter);
        }
    };

    priority_queue<HeapEntry, vector<HeapEntry>, greater<HeapEntry>> min_heap;

    for (size_t i = 0; i < matrix.size(); i++) {
        min_heap.emplace(HeapEntry{
            matrix[i].cbegin(),
            matrix[i].cend(),
        });
    }

    for (int i = 0; i < k - 1; i++) {
        HeapEntry smallest = min_heap.top();
        min_heap.pop();
        if (++(smallest.iter) != smallest.end) {
            min_heap.emplace(smallest);
        }
    }

    return *(min_heap.top().iter);
}
