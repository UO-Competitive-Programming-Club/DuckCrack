#include "../Debug.h"

using namespace std;

/* this problems is same as the problem in the array section */
template <typename T>
shared_ptr<ListNode<T>> RemoveDuplicatesSortedList(shared_ptr<ListNode<T>>& head) {
    auto write_iter = head, match_iter = head;
    while (match_iter) {
        if (match_iter->data != write_iter->data) {
            write_iter->next->data = match_iter->data;
            write_iter = write_iter->next;
        }

        match_iter = match_iter->next;
    }

    write_iter->next = nullptr; 
    return head;
}


int main(void) {
    vector<int> A = {1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,6,7,9,10,10,10};
    auto LL = VectorToLinkedList(A);
    LL = RemoveDuplicatesSortedList(LL);
    PrintList(LL);
    return 0;
}
