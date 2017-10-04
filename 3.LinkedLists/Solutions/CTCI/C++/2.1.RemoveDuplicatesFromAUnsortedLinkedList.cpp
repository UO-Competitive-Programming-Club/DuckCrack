#include "../Debug.h"
using namespace std;

template <typename T>
void DeleteNext(shared_ptr<ListNode<T>>& prev_node) {
    if (prev_node && prev_node->next) {
        prev_node->next = prev_node->next->next;
    }
}

template <typename T>
shared_ptr<ListNode<T>> RemoveDuplicatesUnsorted(shared_ptr<ListNode<T>>& head) {
    unordered_set<T> value_hash;
    auto iter = head;
    value_hash.insert(iter->next->data);
    while (iter && iter->next) {
        if (value_hash.find(iter->next->data) != value_hash.end()) {
            DeleteNext(iter);
        } else {
            value_hash.insert(iter->next->data);
        }

        iter = iter->next;
    }

    return head;
}

int main(){
    vector<int> A = {1,1,2,3,4,5,6,7,7};
    auto LL = VectorToLinkedList(A);
    RemoveDuplicatesUnsorted(LL);
    PrintList(LL);

    return 0;
}
