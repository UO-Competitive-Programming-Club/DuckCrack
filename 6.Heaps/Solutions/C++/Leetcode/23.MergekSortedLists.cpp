#include "../Debug.h"

using namespace std;

 struct LeetCodeListNode {
     int val;
     LeetCodeListNode *next;
     LeetCodeListNode(int x) : val(x), next(NULL) {}
 };

struct Entry {
	LeetCodeListNode* node;
	bool operator<(const Entry& that) const {
		return node->val > that.node->val;
	}
};

LeetCodeListNode* mergeKLists(vector<LeetCodeListNode*>& lists) {
	priority_queue<Entry, vector<Entry>, less<Entry> > min_heap;
	LeetCodeListNode* Dummyhead = new LeetCodeListNode(0);
	LeetCodeListNode* tail = Dummyhead;
	for (LeetCodeListNode * list: lists) {
		if (list) {
			min_heap.emplace( Entry { list } );
		}
	}

	while (!min_heap.empty()) {
		auto smallestEntry = min_heap.top();
		min_heap.pop();
		
		tail->next = smallestEntry.node;
		tail = smallestEntry.node;
		
		if (smallestEntry.node->next) {
			min_heap.emplace(Entry { smallestEntry.node->next });
		}
		
		smallestEntry.node->next = nullptr;
	}
	return Dummyhead->next;
}
