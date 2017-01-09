#include "../Debug.h"
using namespace std;

template <typename T>
shared_ptr<ListNode<T>> DeleteKthToTheTail(shared_ptr<ListNode<T>> & head) {
    auto dummy_head = make_shared<ListNode<T>>(INT_MIN, head),
         front_iter = AdvanceListIter(head),
         back_iter = head;
    
    if (!front_iter) {
        dummy_head->next = head->next;
        return dummy_head->next;
    }


    while (front_iter->next) {
        back_iter = back_iter->next;
        front_iter = front_iter->next;
    }

    back_iter->next = back_iter->next->next;
    
    return head;
}
