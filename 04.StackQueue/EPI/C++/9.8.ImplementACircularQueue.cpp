#include "../Debug.h"
using namespace std;

class CircularQueue {
public:
    explicit CircularQueue(size_t capacity)  : entries_(capacity) {}

    void Enqueue(int x) {
        if (num_elements == entries_.size()) {
            rotate(entries_.begin(), entries_.begin() + head_, entries_.end());
            head_ = 0, tail_ = num_elements;
            entries_.resize(entries_.size() * ksacle_factor);
        }

        entries_[tail_] = x;
        tail_ = (tail_ + 1) % entries_.size();
      ++num_elements;
    }

    int Dequeue() {
        if (!num_elements) {
            throw length_error("Dequeue() : empty queue");
        }

        --num_elements;
        int ret = entries_[head_];
        head_ = (head_ + 1) % entries_.size();

        return ret;
    }

    size_t size() const { return num_elements; }

private:
    const int ksacle_factor = 2;
    size_t head_ = 0, tail_ = 0, num_elements = 0;
    vector<int> entries_;

};
