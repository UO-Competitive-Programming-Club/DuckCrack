#include "../Debug.h"
using namespace std;

template <typename T>
shared_ptr<ListNode<T>> ListPivoting(shared_ptr<ListNode<T>>& head, int k) {
    auto less_head = make_shared<ListNode<T>>(INT_MIN), 
         less_tail = less_head,

         equal_head = make_shared<ListNode<T>>(0), 
         equal_tail = equal_head,

         greater_head = make_shared<ListNode<T>>(INT_MAX), 
         greater_tail = greater_head,

         dummy_head = make_shared<ListNode<T>>(0, head);

    while (dummy_head->next) {
        auto temp = dummy_head->next;
        dummy_head->next = temp->next;
        temp->next = nullptr;

        if (temp->data < k) {
            less_tail->next = temp;
            less_tail = less_tail->next;
        } else if (temp->data > k) {
            greater_tail->next = temp;
            greater_tail = greater_tail->next;
        } else {
            equal_tail->next = temp;
            equal_tail = equal_tail->next;
        }
    }


    less_tail->next = equal_head->next;
    equal_tail->next = greater_head->next;
    head = less_head->next;

    return head;
}

int main(void) {
    vector<int> A = {9,8,7,6,5,4,3,2,1};
    auto LL = VectorToLinkedList(A);
    std::cout << "input: " << std::endl;
    PrintList(LL);
    auto head = ListPivoting(LL, 7);
    std::cout << "output: " << std::endl;
    PrintList(head);
    return 0;
}
