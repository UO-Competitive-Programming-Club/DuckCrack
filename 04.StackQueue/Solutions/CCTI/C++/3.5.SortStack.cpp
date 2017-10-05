#include "../Debug.h"
using namespace std;

template <typename T>
void SortStack(stack<T>& S){
    stack<int> sorted_stack;

    while (!S.empty()) {

        T cur = S.top();
        S.pop();

        while (!sorted_stack.empty() && sorted_stack.top() < cur) {
            S.emplace(sorted_stack.top());
            sorted_stack.pop();
        }

        sorted_stack.emplace(cur);
    }

    S = sorted_stack;
}

int main() {
    vector<int> A = {3,2,4,5,3,2,1,2,3,4,5,3,1,2,110};
    stack<int> S = VectorToStack(A);
    PrintStack(S);
    std::cout << "after sorted:" << std::endl;      
    SortStack(S);
    PrintStack(S);

    return 0;
}
