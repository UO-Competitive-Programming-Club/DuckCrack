#include "../Debug.h"
using namespace std;

/* this function reverse the sublist after the head node not including
 * the head node */ 
template <typename T>
shared_ptr<ListNode<T>> ReverseSubList(shared_ptr<ListNode<T>>& head) {
    auto sublist_head = head,
         sublist_tail = head->next;

    while (sublist_tail && sublist_tail->next) {
        auto temp = sublist_tail->next;
        sublist_tail->next = temp->next;
        temp->next = sublist_head->next;
        sublist_head->next = temp;
    }

    return sublist_head;
}


template <typename T>
bool IsPalindrom(shared_ptr<ListNode<T>>& head) {
    auto slow_iter = head, fast_iter = head;

    while (fast_iter && fast_iter->next && fast_iter->next->next ) {
        slow_iter = slow_iter->next;
        fast_iter = fast_iter->next->next;
    }

    /* reverse the second part of the list */
    ReverseSubList(slow_iter);

    PrintList(head);
    auto back_sublist_iter = slow_iter->next,
         front_sublist_iter = head;
    
    while (back_sublist_iter) {
        if (front_sublist_iter->data != back_sublist_iter->data) {
            return false;
        }
        back_sublist_iter = back_sublist_iter->next;
        front_sublist_iter = front_sublist_iter->next;
    }

    return true;
}

int main(void) {
    vector<int> A = {1};
    auto LL = VectorToLinkedList(A);
    std::cout << IsPalindrom(LL) << std::endl;
    return 0;
}
