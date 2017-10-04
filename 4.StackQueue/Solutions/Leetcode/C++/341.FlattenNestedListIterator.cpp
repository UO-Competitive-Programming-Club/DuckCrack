#include "../Debug.h"
using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int nlsize = nestedList.size();
        for (int i = nlsize - 1; i >= 0; --i) {
            iter_stack_.emplace(nestedList[i]);
        }
    }

    int next() {
        int ret = iter_stack_.top().getInteger();
        iter_stack_.pop();
        return ret;
    }

    bool hasNext() {
        while (!iter_stack_.empty() && !iter_stack_.top().isInteger()) {
            NestedInteger top_element = iter_stack_.top();
            iter_stack_.pop();
            int lsize = top_element.getList().size();
            for (int i = lsize - 1; i >= 0; --i) {
                iter_stack_.emplace(top_element.getList()[i]);
            }
        }

        return !iter_stack_.empty();
    }

private:
    stack<NestedInteger> iter_stack_;
};
