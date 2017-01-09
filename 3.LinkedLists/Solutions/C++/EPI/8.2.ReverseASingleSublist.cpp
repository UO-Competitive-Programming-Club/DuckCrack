#include "../Debug.h"
using namespace std;

template <typename T>
shared_ptr<ListNode<T>> ReverseList(shared_ptr<ListNode<T>>& head, int start, int end) {
    /* using a dummy head to resolve special cases */
    shared_ptr<ListNode<T>> dummy_head = make_shared<ListNode<T>>(INT_MAX, head),
                            iter = dummy_head, 
                            sublist_head,
                            sublist_tail;

    for (int i = 0; i < start - 1; i++) {
        iter = iter->next;
    }

    sublist_head = iter; 
    sublist_tail = iter->next;

    while (start++ < end) {
        auto temp = sublist_tail->next;
        sublist_tail->next = sublist_tail->next->next;
        temp->next = sublist_head->next;
        sublist_head->next = temp;
    }

    head = dummy_head->next;
    return dummy_head->next;
}

int main(void) {
    vector<int> A = {1,3,5,7,9,11,13};
    auto LL = VectorToLinkedList(A),
         RLL = ReverseList(LL, 1, 8);

    PrintList(LL);
    PrintList(RLL);
    return 0;
}
