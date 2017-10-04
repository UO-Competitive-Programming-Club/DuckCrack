#include "../Debug.h"
    
using namespace std;

template <typename T>
shared_ptr<ListNode<T>> DeleteAllElementHasValue(shared_ptr<ListNode<T>>& head, const T& target) {
    auto dummy_head = make_shared<ListNode<T>>(INT_MAX, head),
         dummy_head2 = make_shared<ListNode<T>>(INT_MAX, dummy_head),
         wr_iter = dummy_head, lookup_iter = dummy_head,
         prev_wr_iter = dummy_head2;
    
    while (lookup_iter) {
        if (lookup_iter->data != target) {
            swap(wr_iter->data, lookup_iter->data);
            wr_iter = wr_iter->next;
            prev_wr_iter = prev_wr_iter->next;
        }

        lookup_iter = lookup_iter->next;
    }

    prev_wr_iter->next = nullptr;
    return dummy_head->next;
}

int main(void) {
    vector<int> A = {1,1,1,7,1,1,2,3,4,5,7,7,7,7,7,7};
    auto LL = VectorToLinkedList(A);

    LL = DeleteAllElementHasValue(LL, 1);

    PrintList(LL);
    return 0;
}
