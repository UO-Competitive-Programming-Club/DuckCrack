#include "../Debug.h"
using namespace std;

template <typename T>
shared_ptr<ListNode<T>> HasCycle(shared_ptr<ListNode<T>>& head) {
    if (!head) { return head; }
    auto fast_iter = head->next, slow_iter = head;

    /* first find out if there is a cycle */
    while (fast_iter != slow_iter && fast_iter && fast_iter->next) {
        slow_iter = slow_iter->next;
        fast_iter = fast_iter->next->next;
    }

    if (slow_iter !=  fast_iter) {
        return nullptr;
    }

    /* find out the length of the cycle */
    auto length_iter = slow_iter->next,
         iter_front = head, 
         iter_back = head;

    int cycle_length = 1;
    while (length_iter != slow_iter) {
        length_iter = length_iter->next;
        ++cycle_length;
    }

    /* find out the start of the cycle */
    for (int i = 0; i < cycle_length; i++) {
        iter_front = iter_front->next;
    }     

    while (iter_back != iter_front) {
        iter_back = iter_back->next;
        iter_front = iter_front->next;
    }

    return iter_front;
}

int main(void) {
    vector<int> A = {1,3,5,7,9,11,13};
    auto LL = VectorToLinkedList(A),
         tail = ListTail(LL),
         cycle_node = Search(LL, 13);

    tail->next = cycle_node;
    auto cycle_entry = HasCycle(LL);

    std::cout << cycle_entry->data << std::endl;
    return 0;
}
