#include "../Debug.h"

using namespace std;

vector<int> KLargestInBinaryHeap(const vector<int>& A, int k) {
    if (k <= 0) {
        return {};
    }

    struct HeapEntry {
        int index, value;
        bool operator<(const HeapEntry& that) const {
            return this->value < that.value;
        }
    };

    priority_queue<HeapEntry, vector<HeapEntry>, less<> > max_heap;

    max_heap.emplace(HeapEntry{ 0, A[0] });

    vector<int> result;

    for (int i = 0; i < k; ++i) {
        int candidate_idx = max_heap.top().index;
        result.emplace_back(max_heap.top().value);

        max_heap.pop();

        int alen = A.size(),
            left_child_idx = 2 * candidate_idx + 1, 
            right_child_idx = 2 * candidate_idx + 2;

        if (left_child_idx < alen) {
            max_heap.emplace( HeapEntry{ left_child_idx, A[left_child_idx] } );
        }

        if (right_child_idx < alen) {
            max_heap.emplace( HeapEntry{ right_child_idx, A[right_child_idx] } );
        }

    }

    return result;
}
