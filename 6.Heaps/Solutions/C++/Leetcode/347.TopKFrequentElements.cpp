#include "../Debug.h"

using namespace std;


vector<int> topKFrequentHeap(vector<int>& nums, int k) {
    vector<int> result;

    if (nums.empty() || k <= 0) {
        return result;
    }

    struct HeapEntry {
        int val, count;
        bool operator>(const HeapEntry& that) const {
            return this->count > that.count;
        }
    };

    priority_queue<HeapEntry, vector<HeapEntry>, greater<HeapEntry>> min_heap;
    unordered_map<int, int> occurance_map;

    for (size_t i = 0; i < nums.size(); i++) {
        (occurance_map.find(nums[i]) == occurance_map.end()) ?
            occurance_map[nums[i]] = 1 :
            occurance_map[nums[i]]++;
    }

    int j = 0; auto iter = occurance_map.begin();
    for ( ; iter != occurance_map.end() && j < k; iter++, j++) {
        min_heap.emplace(HeapEntry{ iter->first, iter->second });
    }

    /* now we have a heap of size k */
    for ( ; iter != occurance_map.end(); iter++) {
        if (min_heap.top().count < iter->second) {
            min_heap.pop();
            min_heap.emplace(HeapEntry{ iter->first, iter->second });
        }
    }

    while (!min_heap.empty()) {
        result.emplace_back(min_heap.top().val);
        min_heap.pop();
    }

    return result;
}
