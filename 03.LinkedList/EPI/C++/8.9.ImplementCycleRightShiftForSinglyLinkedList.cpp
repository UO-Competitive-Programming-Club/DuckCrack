#include "../Debug.h"
using namespace std;

template <typename T>
shared_ptr<ListNode<T>> CycleLeftShift(shared_ptr<ListNode<T>>& head, int k) {
    if (k <= 0) { return head; }

    int llen = ListLength(head), shift_amount = k % llen;
    auto dummy_head = make_shared<ListNode<T>> (INT_MAX, head), 
         tail = AdvanceListIter(head, llen - 1);

    std::cout << tail->data << std::endl;
    while (shift_amount-- > 0) {
        auto temp = dummy_head->next;
        dummy_head->next = temp->next;
        tail->next = temp;
        tail = temp;
        tail->next = nullptr;
    }

    return dummy_head->next;
}

template <typename T>
shared_ptr<ListNode<T>> CycleRightShift(shared_ptr<ListNode<T>>& head, int k) {
    if (k <= 0) { return head; }
    int llen = ListLength(head), shift_amount = k % llen;
    return CycleLeftShift(head, llen - shift_amount);

}

int main(void) {
    vector<int> A = {1,2,3,4,5,6,7,8,9,10};
    auto LL = VectorToLinkedList(A);
    LL = CycleRightShift(LL, 3);
    PrintList(LL);
    return 0;
}
