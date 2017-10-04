#include "../Debug.h"
using namespace std;

struct Entry {
    vector<int>::const_iterator iter;
    vector<int>::const_iterator end;
    bool operator<(const Entry& that) const {
        return *iter > *that.iter;
    }
};

vector<int> MergeSortedArray(const vector<vector<int>>& files) {
    priority_queue<Entry, vector<Entry>, less<Entry> > min_heap;
    vector<int> result;
    for (const vector<int>& file: files) {
        if (!file.empty()) {
            min_heap.emplace( Entry { file.begin(), file.end() } );
        }
    }

    while (!min_heap.empty()) {
        auto smallestEntry = min_heap.top();
        min_heap.pop();

        result.emplace_back(*smallestEntry.iter);
        if (++(smallestEntry.iter) != smallestEntry.end) {
            min_heap.emplace(smallestEntry);
        }

    }

    return result;
}

vector<int> SortArray(const vector<int>& A) {
    vector<vector<int>> sorted_subarrays;
    typedef enum { INCREASING, DECREASING } SubarrayType;
    SubarrayType subarray_type = INCREASING;

    int start_idx = 0;
    for (size_t i = 0; i < A.size(); i++) {
        if (i == A.size() || 
            (A[i - 1] < A[i] && subarray_type == DECREASING) ||
            (A[i - 1] >= A[i] && subarray_type == INCREASING)) { 

            if (subarray_type == INCREASING) {
                sorted_subarrays.emplace_back(A.cbegin() + start_idx, A.cbegin() + i);
            } else {
                sorted_subarrays.emplace_back(A.cbegin() + A.size() - i, 
                                              A.cbegin() + A.size() - start_idx);
            }

            start_idx = i;
            subarray_type = (subarray_type == INCREASING ? DECREASING : INCREASING);
        }
    }

    return MergeSortedArray(sorted_subarrays);
}
