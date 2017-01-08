#include <iostream> 
#include <memory> 
using namespace std;

template <typename T>
struct SinglyListNode {
    T data;
    shared_ptr<SinglyListNode<T>> next;
    SinglyListNode(T data) {
        this->data = data;
        this->next = nullptr;
    }

    SinglyListNode(T data, shared_ptr<SinglyListNode<T>> next) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
int ListLength(shared_ptr<SinglyListNode<T>>& head) {
    if (head == nullptr) {
        return 0;
    }

    return ListLength(head->next) + 1;
}

template <typename T>
shared_ptr<SinglyListNode<T>> Search(shared_ptr<SinglyListNode<T>>& head, T data) {
    if ((head == nullptr) || (head->data == data)) {
        return head; 
    }

    return Search(head->next, data);
}

template <typename T>
void PrintList(shared_ptr<SinglyListNode<T>>& head) {
    if (head != nullptr) {
        cout << head->data << "->" << endl;
        PrintList(head->next);
    } 
}

/* reconstructing list template */
template <typename T>
shared_ptr<SinglyListNode<T>> Construct(shared_ptr<SinglyListNode<T>>& head) {
    if (head == nullptr) {
        return nullptr;
    } else {
        head->next = construct(head->next);
        return head;
    }
}

template <typename T>
shared_ptr<SinglyListNode<T>> InsertSorted(shared_ptr<SinglyListNode<T>>& head, T data) {
    if (head == nullptr) {
        return make_shared<SinglyListNode<T>>(data);
    } else if (head->data >= data) {
        return make_shared<SinglyListNode<T>>(data, head);
    } else {
        head->next = InsertSorted( head->next, data);
        return head;
    }
}

