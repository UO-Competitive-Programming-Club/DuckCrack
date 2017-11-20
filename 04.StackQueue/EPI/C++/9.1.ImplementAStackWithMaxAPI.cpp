#include "../Debug.h"

using std::stack;
using std::length_error;

template <typename T>
class MaxStack {
public:
    void push(T new_data) {
        rs.push(new_data);
        if (rs.empty() || new_data > ms.top().val) {
            ms.push(MaxCounter(new_data));
        } else if (new_data == ms.top().val) {
            ++(ms.top().count);
        }
    }

    void pop() { 
        if (!rs.empty()) {
            T popped = rs.top();
            rs.pop();
            if (popped == ms.top().val) { --(ms.top().count); } 
            if (ms.top.count == 0) { ms.pop(); }
        } else {
            throw length_error("pop(): empty stack");
        }
    
    }

    T max() const {
        if (!rs.empty()) {
            return ms.top().val;
        } else {
            throw length_error("pop(): empty stack");
        }

    }

    T top() const {
        if (!rs.empty()) {
            return ms.top().val;
        } else {
            return rs.top();
        }
    }

    T empty() const {
        return rs.empty();
    }

private:
    struct MaxCounter {
        T val;
        int count;
        MaxCounter(T new_max) : 
            val(new_max), count(1){};
    };

    stack<T> rs;
    stack<MaxCounter> ms;
};
