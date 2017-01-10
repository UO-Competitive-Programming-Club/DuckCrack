#include "../Debug.h"
using namespace std;

template <typename T>
shared_ptr<ListNode<T>> DeleteMiddleElement(shared_ptr<ListNode<T>>& head) {
    auto dummy_head = make_shared<ListNode<T>>(INT_MAX, head),
         fast_iter = dummy_head, slow_iter = dummy_head;

    while (fast_iter && fast_iter->next && fast_iter->next->next) {
        fast_iter = fast_iter->next->next;
        slow_iter = slow_iter->next;
    }

    if (slow_iter && slow_iter->next) {
        slow_iter->next = slow_iter->next->next;
    }

    return dummy_head->next;
}

int main(){
    vector<int> A = {1};
    auto LL = VectorToLinkedList(A);
    LL = DeleteMiddleElement(LL);
    PrintList(LL);

    return 0;
}
