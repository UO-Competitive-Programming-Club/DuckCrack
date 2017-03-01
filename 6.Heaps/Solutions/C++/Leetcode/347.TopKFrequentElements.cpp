#include "../Debug.h"

using namespace std;

vector<int> topKFrequentHeap(vector<int>& nums, int k) {
    vector<int> result;
    if (nums.empty() || k <= 0) {
        return result;
    }

    unordered_map<int, int> occurance_map;

    for (size_t i = 0; i < nums.size(); i++) {
        
    }
}

