#include "../Debug.h"

using namespace std;

bool DoBracketsMatch(string expr) {
    stack<char> bracket_stack;
    for (size_t i = 0; i < expr.size(); i++) {
        if (expr[i] == '{' || expr[i] == '[' || expr[i] == '(') {
            bracket_stack.emplace(expr[i]);
        } else if (expr[i] == '}' || expr[i] == ']' || expr[i] == ')') {
            if (bracket_stack.empty()) {
                return false;
            }

            char left_bracket = bracket_stack.top();
            if ((expr[i] == '{' && left_bracket != '}') || 
                (expr[i] == '[' && left_bracket != ']') || 
                (expr[i] == '(' && left_bracket != ')')) {
                return false;
            }

            bracket_stack.pop();
        }     
    }

    return bracket_stack.empty();
}

int main(void)  {
    string expr = "[[[[[,]]]]asdawasdfjal[][][][][]()()(){}{}{{}{}{}{}{}}{}]";
    std::cout << DoBracketsMatch(expr) << std::endl;
    return 0;
}
