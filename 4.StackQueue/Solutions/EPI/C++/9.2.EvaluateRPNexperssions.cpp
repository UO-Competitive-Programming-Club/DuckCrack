#include "../Debug.h"  
using namespace std;

int EvalRPN(string expr) {
    stack<int> cal_stack;
    stringstream ss(expr);
    string token;
    const char delimiter = ',';

    int result;
    while (getline(ss, token, delimiter)) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int x = cal_stack.top();
            cal_stack.pop();
            int y = cal_stack.top();
            cal_stack.pop();
            switch(token.front()) {
                case('+'):
                    result = x + y;
                    break;
                case('-'):
                    result = x - y;
                    break;
                case('*'):
                    result = x * y;
                    break;
                case('/'):
                    result = x / y;
                    break;
            }
            cal_stack.emplace(result);
        } else {
            cal_stack.emplace(stoi(token));
        }
    }

    return result;
}

int main() {
    string expression = "3,4,+,2,*,1,+";

    std::cout << EvalRPN(expression) << std::endl;

    return 0;
}
