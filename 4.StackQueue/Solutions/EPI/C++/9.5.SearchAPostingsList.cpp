#include "../Debug.h"
using namespace std;

template <typename T>
struct PostingListNode {
    T data;
    std::shared_ptr<ListNode<T>> next, jump;
    int order;

    PostingListNode(T data) {
        this->data = data;
        this->next = nullptr;
        this->jump = nullptr;
        this->order = -1;
    }

    PostingListNode(T data, shared_ptr<PostingListNode<T>>& next, 
            shared_ptr<PostingListNode<T>>& jump) {
        this->data = data;
        this->next = next;
        this->jump = jump;
        this->order = -1;
    }
};

template <typename T>
void SetJumpOrder(const shared_ptr<PostingListNode<T>>& L) {
    



}
