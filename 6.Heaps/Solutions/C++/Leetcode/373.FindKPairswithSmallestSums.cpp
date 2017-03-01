#include "../Debug.h"

using namespace std;

struct PairEntry {
	int A_val, A_idx,
		B_val, B_idx;
	bool operator>(const PairEntry& that) const {
		return ((this->A_val + this->B_val) > (that.A_val + that.B_val));
	}
};

vector<pair<int, int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {
	vector<pair<int, int>> result;
	
	if (A.empty() || B.empty() || k <= 0) {
		return result;
	}
	
	priority_queue<PairEntry, vector<PairEntry>, greater<PairEntry> > min_heap;
	min_heap.emplace(
		PairEntry{
			A[0], 0,
			B[0], 0
		}
	);

	for (int i = 0; i < k && !min_heap.empty(); i++) {
		PairEntry cannidate = min_heap.top();
		min_heap.pop();
		result.emplace_back(pair<int, int>{ cannidate.A_val, cannidate.B_val });
		
		if (cannidate.A_idx + 1 < (int) A.size()) {
			int new_A_idx = cannidate.A_idx + 1;
			min_heap.emplace( PairEntry { 
				A[new_A_idx], new_A_idx,
				cannidate.B_val, cannidate.B_idx
			});
		}

		if (cannidate.A_idx == 0 && cannidate.B_idx + 1 < (int) B.size()) {
			int new_B_idx = cannidate.B_idx + 1;
			min_heap.emplace(PairEntry {
				cannidate.A_val, cannidate.A_idx,
				B[new_B_idx], new_B_idx,
			});
		}

	}

	return result;
}

