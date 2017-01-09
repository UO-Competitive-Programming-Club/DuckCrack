#include "../Debug.h"
using namespace std;
template <typename T>

static shared_ptr<ListNode<T>> HasCycle(shared_ptr<ListNode<T>>& head) {
    if (!head) { return head; }
    auto fast_iter = head->next, slow_iter = head;

    /* first find out if there is a cycle */
    while (fast_iter != slow_iter && fast_iter && fast_iter->next) {
        slow_iter = slow_iter->next;
        fast_iter = fast_iter->next->next;
    }

    if (slow_iter !=  fast_iter) {
        return nullptr;
    }

    /* find out the length of the cycle */
    auto length_iter = slow_iter->next,
         iter_front = head, 
         iter_back = head;

    int cycle_length = 1;
    while (length_iter != slow_iter) {
        length_iter = length_iter->next;
        ++cycle_length;
    }

    /* find out the start of the cycle */
    for (int i = 0; i < cycle_length; i++) {
        iter_front = iter_front->next;
    }     

    while (iter_back != iter_front) {
        iter_back = iter_back->next;
        iter_front = iter_front->next;
    }

    return iter_front;
}
template <typename T>
static shared_ptr<ListNode<T>> IsOverlapNoCycle(shared_ptr<ListNode<T>>& L1, 
        shared_ptr<ListNode<T>>& L2) {
    int L1Len = ListLength(L1), L2Len = ListLength(L2);

    auto iter1 = L1, iter2 = L2; 
    if (L1Len > L2Len) {
        for (int i = 0; i < L1Len - L2Len; i++) {
            iter1 = iter1->next;
        }
    } else {
        for (int i = 0; i < L2Len - L1Len; i++) {
            iter2 = iter2->next;
        }
    }

    while (iter1 && iter2) {
        if (iter1 == iter2) {
            return iter1;
        } 

        iter1 = iter1->next;
        iter2 = iter2->next;
    }

    return nullptr;
}
    
template <typename T>
static shared_ptr<ListNode<T>> CyclicListLength(shared_ptr<ListNode<T>>& L1, 
        shared_ptr<ListNode<T>>& cycle_entry) {

    auto before_cycle_iter = L1,
         after_cycle_iter = cycle_entry->next;

    int length = 1;
    while (before_cycle_iter != cycle_entry) {
        ++length;
    } 

    while (after_cycle_iter != cycle_entry) {
        ++length;
    } 
        
    return length;
}


template <typename T>
shared_ptr<ListNode<T>> IsOverlap(shared_ptr<ListNode<T>>& L1, 
        shared_ptr<ListNode<T>>& L2) {

    /* first we find out if each of them has cycle exist */
    auto L1CycleEntry = HasCycle(L1), 
         L2CycleEntry = HasCycle(L2);


    /* if both of them have cycles */
    if (L1CycleEntry || L2CycleEntry) {

        return nullptr;

    /* if both of them do not have cycles */
    } else if (!L1CycleEntry && !L2CycleEntry) {

        return IsOverlapNoCycle(L1, L2);

    /* the case we don't care, one has cycle has one doesn't */ 
    } else {

        /* check if they end in the same cycle */
        auto temp = L1CycleEntry->next;
        while (temp != L2CycleEntry && temp != L1CycleEntry) {
            temp = temp->next;
        }

        /* if they don't end in the same cycle they don't overlapp */
        if (temp != L2CycleEntry) {
            return nullptr;
        }

        /* if they do end in the same cycle */

        /* find the length of L1 and L2 */
        int L1Len = CyclicListLength(L1, L1CycleEntry),
            L2Len = CyclicListLength(L2, L2CycleEntry);

        auto iter1 = L1, iter2 = L2; 
        (L1Len > L2Len) ?
            iter1 = AdvanceListIter(iter1, abs(L1Len - L2Len)):
            iter2 = AdvanceListIter(iter2, abs(L1Len - L2Len));

        while (iter1 != iter2) {
            iter1 = iter1->next;
            iter2 = iter2->next;
        }

        return iter1;
    }
}
