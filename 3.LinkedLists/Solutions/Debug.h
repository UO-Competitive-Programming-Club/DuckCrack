#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <limits>
#include <climits>
#include <queue>
#include <stack>
#include <memory>
#include <algorithm>
#include <random>
#include <sstream>

/* arrays */

template <typename T>
void print_vector(const std::vector<T>& A) {
    if (A.empty()) {
        std::cout << "empty vector" << std::endl;
    } else {
        std::cout << "[ ";
        for (size_t i = 0; i < A.size(); ++i) {
            std::cout << A[i];
            if (i != A.size() - 1) {
                std::cout << ", ";
            }
        }

        std::cout << " ]" << std::endl;
    }
}

template <typename T>
void print_matrix(const std::vector<std::vector<T>>& matrix) { 
    int height = matrix.size();
    for (int i = 0; i < height; i++) {
         print_vector(matrix[i]);
    }
}

/* linked list */
template <typename T>
struct ListNode {
    T data;
    std::shared_ptr<ListNode<T>> next;
    ListNode(T data) {
        this->data = data;
        this->next = nullptr;
    }

    ListNode(T data, std::shared_ptr<ListNode<T>> next) {
        this->data = data;
        this->next = next;
    }
};
/* get the length of the list */
template <typename T>
int ListLength(std::shared_ptr<ListNode<T>>& head) {
    if (head == nullptr) {
        return 0;
    }
    return ListLength(head->next) + 1;
}

/* print list */ 
template <typename T>
void PrintList(std::shared_ptr<ListNode<T>>& head) {
    if (head != nullptr) {
        std::cout << head->data << " -> ";
        PrintList(head->next);
    } else {
        std::cout <<  std::endl;
    }
}

/* insert in the end */
template <typename T>
std::shared_ptr<ListNode<T>> Insert(std::shared_ptr<ListNode<T>>& head, T data) {
    if (head == nullptr) {
        return std::make_shared<ListNode<T>>(data);
    } else {
        head->next = Insert(head->next, data);
        return head;
    }
}


template <typename T>
std::shared_ptr<ListNode<T>> Search(std::shared_ptr<ListNode<T>>& head, T data) {
    if ((head == nullptr) || (head->data == data)) {
        return head; 
    }

    return Search(head->next, data);
}

template <typename T>
std::shared_ptr<ListNode<T>> ListTail(std::shared_ptr<ListNode<T>>& head) {
    if ((head == nullptr) || (head->next == nullptr)) {
        return head; 
    }

    return ListTail(head->next);
}

template <typename T>
std::shared_ptr<ListNode<T>> AdvanceListIter(std::shared_ptr<ListNode<T>>& iter, int distance) {
    if (distance == 0 || !(iter->next)) {
        return iter;
    }

    return AdvanceListIter(iter->next, distance - 1);
}

template <typename T>
std::shared_ptr<ListNode<T>> AppendLists(std::shared_ptr<ListNode<T>>& head1, 
        std::shared_ptr<ListNode<T>>& head2) {
    if (head1 == nullptr) {
        return head2;
    } else {
        head1->next = AppendLists(head1->next, head2);
        return head1;
    }
}

template <typename T>
std::shared_ptr<ListNode<T>> VectorToLinkedList(std::vector<T>& A) {
    if (A.empty()) {
        std::cout << "input is empty" << std::endl;
        return nullptr;
    } else {
        auto head = std::make_shared<ListNode<T>>(A[0]);
        for (size_t i = 1; i < A.size(); i++) {
            head = Insert(head, A[i]);
        }
        return head;
    }

}
#endif
