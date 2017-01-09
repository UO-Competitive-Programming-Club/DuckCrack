#include "../Debug.h"
using namespace std;

template <typename T>
shared_ptr<ListNode<T>> DeleteKthToTheTail(shared_ptr<ListNode<T>> & head, int k) {
    auto dummy_head = make_shared<ListNode<T>>(INT_MIN, head),
         front_iter = AdvanceListIter(head, k),
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

int main(void) {
    vector<int> A = {9,8,7,6,5,4,3,2,1};
    auto LL = VectorToLinkedList(A);
    PrintList(LL);
    auto head = DeleteKthToTheTail(LL, 9);
    PrintList(head);
    return 0;
}
