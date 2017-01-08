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

/* insert to a sorted list */
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

/* delete an element */
template <typename T>
shared_ptr<SinglyListNode<T>> Delete(shared_ptr<SinglyListNode<T>>& head, T data) {
    if (head == nullptr) {   // if the list is ordered use:  ( p == null || p.item > k )
        return make_shared<SinglyListNode<T>>(data);
    } else if (head->data == data) {
        return head->next;   // if you want to delete all instances, use:  return Delete( head->next, data);  
    } else {
        head->next = Delete( head->next, data);
        return head;
    }
}

/* delete the last element of the linkedlist */
template <typename T>
shared_ptr<SinglyListNode<T>> DeleteTail(shared_ptr<SinglyListNode<T>>& head, T data) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    } else {
        head->next = DeleteTail( head->next, data);
        return head;
    }
}

/* added two lists together */
template <typename T>
shared_ptr<SinglyListNode<T>> AppendLists(shared_ptr<SinglyListNode<T>>& head1, 
        shared_ptr<SinglyListNode<T>>& head2) {
    if (head1 == nullptr) {
        return head2;
    } else {
        head1->next = AppendLists(head1->next, head2);
        return head1;
    }
}

/* zip two lists */
template <typename T>
shared_ptr<SinglyListNode<T>> ZipLists(shared_ptr<SinglyListNode<T>>& head1, 
        shared_ptr<SinglyListNode<T>>& head2) {
    if (head1 == nullptr) {
        return head2;
    } else {
        head1->next = ZipLists(head2, head1->next);
        return head1;
    }
}

/* merge two sorted list */
template <typename T>
shared_ptr<SinglyListNode<T>> MergeLists(shared_ptr<SinglyListNode<T>>& head1,
        shared_ptr<SinglyListNode<T>>& head2) {
    if (head1 == nullptr) {
        return head2;
    } else if ( head2 == nullptr ) {
        return head1;
    } else if (head1.data < head2.data) {
        head1.next = MergeLists(head1.next, head2);
        return head1;
    } else {
        head2.next = MergeLists(head1, head2->next);
        return head2;
    }
}
