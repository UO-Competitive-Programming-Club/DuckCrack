#include "../Debug.h"

using namespace std;

/* solution 1 using two stacks */ 
void ReverseStackHelper(stack<int>& S, stack<int>& rS) {
    if (!S.empty()) {
        rS.emplace(S.top());
        S.pop();
        ReverseStackHelper(S, rS);
    }
}

void ReverseStack(stack<int>& S) {
    stack<int> rS;
    ReverseStackHelper(S, rS);
    S = rS;
}


/* Solution 2 using only one stack but more memory and time complexity */
void InsertAtBottom(stack<int>& S, int item) {
    if (S.empty()) {
        S.emplace(item);
    } else {
        int popped = S.top();
        S.pop();
        InsertAtBottom(S, item);
        S.emplace(popped);
    }
}

void ReverseStack2(stack<int>& S) {
    if (!S.empty()) {
        int temp = S.top();
        S.pop();
        ReverseStack2(S);
        /* std::cout << temp << std::endl; */
        InsertAtBottom(S, temp);
    }
}

int main() {
    vector<int> A = {1,2,3,4,5,6,7,8,9};
    stack<int> S = VectorToStack(A);
   
    ReverseStack2(S);
    PrintStack(S);

    return 0;
}
