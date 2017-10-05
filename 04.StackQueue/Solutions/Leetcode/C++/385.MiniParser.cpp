#include "../Debug.h"
using namespace std;

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

NestedInteger deserialize(string s) {
	stack<NestedInteger> nestint_stack;
	nestint_stack.emplace(NestedInteger());
	string single_ni;

	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == '[') {
			nestint_stack.emplace(NestedInteger());
		} else if (s[i] == ']' || s[i] == ',') {
			if (single_ni.size() > 0) {
				nestint_stack.top().add(NestedInteger(stoi(single_ni)));
				single_ni.clear();
			}
			
			if (s[i] == ']') {
				NestedInteger closed_ni = nestint_stack.top();
				nestint_stack.pop();
				nestint_stack.top().add(closed_ni);
			}
			
		} else if (isdigit(s[i]) || s[i] == '-') {
			single_ni += s[i];
		}
	}

    /* case where input is "124123" without squre bracket */ 
	if (!single_ni.empty()) {
		return NestedInteger(stoi(single_ni));
	}

	return nestint_stack.top().getList().front();
}
