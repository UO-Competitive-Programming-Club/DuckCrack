#include "../Debug.h"
using namespace std;
template <typename T>
shared_ptr<ListNode<T>> MergeTwoSortedListsIterative(shared_ptr<ListNode<T>>& L1,
        shared_ptr<ListNode<T>>& L2) {

    shared_ptr<ListNode<T>> dummy_head     = make_shared<ListNode<T>>(INT_MAX),
                            current_parent = dummy_head,
                            iter1 = L1, 
                            iter2 = L2;
         
    while (iter1 && iter2 ) {
        auto cur_smaller_node = (iter1->data < iter2->data) ? iter1 : iter2;
        (iter1->data < iter2->data) ? iter1 = iter1->next : iter2 = iter2->next;

        cur_smaller_node->next = nullptr;
        current_parent->next = cur_smaller_node;
        current_parent = cur_smaller_node;
    }

    (iter1) ? current_parent->next = iter1 : current_parent->next = iter2;

    return dummy_head->next;
} 

int main(void) {
    vector<int> A = {1,3,5,7,9,11,13};
    vector<int> B = {13};
    auto LL = VectorToLinkedList(A),
         LL2 = VectorToLinkedList(B),
         MLL = MergeTwoSortedListsIterative(LL2, LL);

    PrintList(MLL);
    return 0;
}
