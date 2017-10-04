#include "../Debug.h"
using namespace std;
   
template <typename T>
shared_ptr<ListNode<T>> EvenOddMerge(shared_ptr<ListNode<T>>& head) {
    auto even_dummy_head = make_shared<ListNode<T>>(INT_MAX),
         odd_tail = head,
         even_tail = even_dummy_head,
         iter = head;

    int isOdd = 1;

    while (iter) {
        if (isOdd) {
            odd_tail = iter;
            iter = iter->next;
        } else {
            auto temp = iter;
            iter = iter->next;
            odd_tail->next = iter;
            even_tail->next = temp;
            even_tail = temp; 
            temp->next = nullptr;
        }

        isOdd ^= 1;
    }

    odd_tail->next = even_dummy_head->next;
    return head;
}

int main(void) {
    vector<int> A = {1,2,3};
    auto LL = VectorToLinkedList(A);
    PrintList(LL);
    auto head = EvenOddMerge(LL);
    PrintList(head);
    return 0;
}
