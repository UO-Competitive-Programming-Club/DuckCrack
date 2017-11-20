#include "../Debug.h"
using namespace std;

template <typename T> 
class StackQueue {
public:
    StackQueue() {};
    void Enque(T data) {
        enqueue_stack_.emplace(data);
        ++size_;
    }

    T Deque() {
        T deq_element;
        if (enqueue_stack_.empty() && dequeue_stack_.empty()) {
            
            throw length_error("Dequeue() : StackQueue is empty");

        } else {

            PrepareDeque();
            deq_element = dequeue_stack_.top();
            dequeue_stack_.pop();
            --size_;
        }

        return deq_element;
    }

    T front() {
        PrepareDeque();
        return dequeue_stack_.top();
    }

    bool Empty() {
        return (size_ == 0);
    }

private:
    stack<T> enqueue_stack_, 
              dequeue_stack_;
    int size_ = 0;

    void PrepareDeque() {
        if (dequeue_stack_.empty()) {
            while (!enqueue_stack_.empty()) {
                dequeue_stack_.emplace(enqueue_stack_.top());
                enqueue_stack_.pop();
            }
        }
    }

};


int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9}; 
    vector<int> v2 = {10,12,13,14,15,16,17,18,19}; 
    StackQueue<int> sq;

    for (auto n : v) {
        sq.Enque(n);
    }

    std::cout << sq.front() << std::endl;

    while (!sq.Empty()) {
        std::cout << sq.Deque() << std::endl;
    }

    for (auto n : v2) {
        sq.Enque(n);
    }

    while (!sq.Empty()) {
        std::cout << sq.Deque() << std::endl;
    }
    return 0;
}
