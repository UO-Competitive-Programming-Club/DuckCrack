#include <iostream> 
#include <memory> 

template <typename T>
struct SinglyListNode {
    T data;
    std::shared_ptr<SinglyListNode<T>> next;
    SinglyListNode(T data) {
        this->data = data;
        this->next = nullptr;
    }

    SinglyListNode(T data, std::shared_ptr<SinglyListNode<T>> next) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
int ListLength(std::shared_ptr<SinglyListNode<T>>& head) {
    if (head == nullptr) {
        return 0;
    }

    return ListLength(head->next) + 1;
}

template <typename T>
std::shared_ptr<SinglyListNode<T>> Search(std::shared_ptr<SinglyListNode<T>>& head, T data) {
    if ((head == nullptr) || (head->data == data)) {
        return head; 
    }

    return Search(head->next, data);
}

template <typename T>
void PrintList(std::shared_ptr<SinglyListNode<T>>& head) {
    if (head != nullptr) {
        std::cout << head->data << "->" << std::endl;
        PrintList(head->next);
    } 
}

/* when changing the structure of the linkedlist */
template <typename T>
std::shared_ptr<SinglyListNode<T>> InsertSorted(std::shared_ptr<SinglyListNode<T>>& head, T data) {
    if (head == nullptr) {
        return std::make_shared<SinglyListNode<T>>(data);
    } else if (head->data >= data) {
        return std::make_shared<SinglyListNode<T>>(data, head);
    } else {
        head->next = InsertSorted( head->next, data);
        return head;
    }
}

