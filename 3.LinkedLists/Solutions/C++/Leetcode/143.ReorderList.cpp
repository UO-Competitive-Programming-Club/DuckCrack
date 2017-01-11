#include "../Debug.h"
using namespace std;

template <typename T>
shared_ptr<ListNode<T>> ReverseSubList(shared_ptr<ListNode<T>>& head) {
    auto tail = head->next;
    while (tail->next) {
        auto temp = tail->next;
        tail->next = temp->next;
        temp->next = head->next;
        head->next = temp;
    }

    return head->next;
}

template <typename T>
shared_ptr<ListNode<T>> ZipLists(shared_ptr<ListNode<T>>& L1, shared_ptr<ListNode<T>>& L2) {
    if (L1 == nullptr) {
        return L2;
    } else {
        L1->next = ZipLists(L2, L1->next);
        return L1;
    }
}
   

template <typename T>
shared_ptr<ListNode<T>> ReorderList(shared_ptr<ListNode<T>>& head) {
    /* first we find the middle node */
    auto dummy_head = make_shared<ListNode<T>>(INT_MAX, head),
         slow_iter = dummy_head, fast_iter = head;

    while (fast_iter && fast_iter->next) {
        fast_iter = fast_iter->next->next;
        slow_iter = slow_iter->next;
    }

    /* reverse the second half list */
    auto second_half_head = ReverseSubList(slow_iter);
    slow_iter->next = nullptr;


    /* zip the first half and the reversed second half */
    return ZipLists(head, second_half_head);
}



int main(void) {
    vector<int> A = {1,2,3,4,5,6,7,8,9},    
                B = {-1,-2,-3,-4,-5,-6,-7,-8,-9};
    auto L1 = VectorToLinkedList(A),
         L2 = VectorToLinkedList(B);

    ReorderList(L1);
    PrintList(L1);
    return 0;
}
