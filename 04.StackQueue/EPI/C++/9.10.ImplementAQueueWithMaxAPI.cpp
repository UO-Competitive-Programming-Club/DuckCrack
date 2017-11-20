#include "../Debug.h"
using namespace std;

template <typename T>
class MaxQueue {
public:
    MaxQueue(){}

    void Enqueue(T data) {
        rq.push_back(data);
        if (mq.empty()) {

            mq.push_back(data);

        } else {

            while (mq.back() < data) {
                mq.pop_back();
            }

            mq.push_back(data);
        }

        size_++;
    }

    void Deque() {
        if (rq.empty()) {
            throw length_error("MaxQueue::Dequeue() : queue is empty");
        }

        if (mq.front() == rq.front()) {
            mq.pop_front();
        }

        rq.pop_front;
        size_--;
    }

    T Front() {
        return rq.front();
    }

    T Back() {
        return rq.Back();
    }

    T Max() {
        return mq.front();
    }


private:
    queue<T> rq,
             mq;
    int size_ = 0;

};
