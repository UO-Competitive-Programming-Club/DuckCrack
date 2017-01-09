#include "../Debug.h"

using namespace std;

template <typename T>
void DeleteNoneTailNode(shared_ptr<ListNode<T>>& target) {
    target->data = target->next->data;
    target->next = target->next->next;
}
