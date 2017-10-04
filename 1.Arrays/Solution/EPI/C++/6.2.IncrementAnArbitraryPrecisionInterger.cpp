#include "../Debug.h"

using namespace std;

vector<int> plusOne(vector<int>& A) {
	vector<int> result(A);
	
	if (result.empty()) {
		return result;
	}
	
    ++result.back();
	int alen = result.size(), carryin = 0, carryout = result.back() / 10;
	result.back() = result.back() % 10;
	
	for (int i = alen - 2; i >= 0; --i) {
		carryin = carryout;
		int digit = (result[i] + carryin) % 10;
		carryout = (result[i] + carryin) / 10;
		result[i] = digit;
	}

	if (carryout) {
		result.insert(result.cbegin(), 1);
	}

	return result;
}
