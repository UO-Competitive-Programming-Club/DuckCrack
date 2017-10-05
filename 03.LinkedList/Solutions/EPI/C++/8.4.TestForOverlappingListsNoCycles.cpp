#include "../Debug.h"

using namespace std;

template <typename T>
shared_ptr<ListNode<T>> IsOverlapNoCycle(shared_ptr<ListNode<T>>& L1, 
        shared_ptr<ListNode<T>>& L2) {

    int L1Len = ListLength(L1), L2Len = ListLength(L2);
    auto iter1 = L1, iter2 = L2; 

    (L1Len > L2Len) ? 
        iter1 = AdvanceListIter(iter1, abs(L1Len - L2Len)) :
        iter2 = AdvanceListIter(iter2, abs(L1Len - L2Len));

    while (iter1 && iter2) {
        if (iter1 == iter2) {
            return iter1;
        } 

        iter1 = iter1->next;
        iter2 = iter2->next;
    }

    return nullptr;
}

int main(void) {
    vector<int> A = {1,2,3,4,5,6,7,8,9},
                B = {-1,-2,-3,-4,-5},
                C = {88,0,0,0,0,0,0,0,0,0};

    auto AL = VectorToLinkedList(A),
         BL = VectorToLinkedList(B),
         CL = VectorToLinkedList(C);

    AppendLists(AL, CL);
    AppendLists(BL, CL);
    
    auto overlap_entry = IsOverlapNoCycle(AL, BL);
    if (overlap_entry) {
        std::cout << overlap_entry->data << std::endl;
    } else {
        std::cout << "No overlap" << std::endl;
    }

    return 0;
}
