#include "../Debug.h"
using namespace std;

struct Entry {
    vector<int>::const_iterator iter;
    vector<int>::const_iterator end;
    bool operator<(const Entry& that) const {
        return *iter > *that.iter;
    }
};

vector<int> SortFiles(const vector<vector<int>>& files) {
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
