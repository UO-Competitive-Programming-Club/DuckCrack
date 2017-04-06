#include "../Debug.h"

using namespace std;

void DirectedGeneratedParentheses(int num_left_parens_needed,
                                  int num_right_parens_needed,
                                  const string& valid_prefix,
                                  vector<string>* result) {
    if (!num_left_parens_needed && !num_right_parens_needed) {
        result->emplace_back(valid_prefix);
    }

    if (num_left_parens_needed > 0) {
        DirectedGeneratedParentheses(num_left_parens_needed - 1,
                                     num_right_parens_needed,
                                     valid_prefix + '(',
                                     result);
    }

    if (num_right_parens_needed > num_left_parens_needed) {
        DirectedGeneratedParentheses(num_left_parens_needed,
                                     num_right_parens_needed - 1,
                                     valid_prefix + ')',
                                     result);
    }
}

 
vector<string> GenerateBalancedParenthses(int num_pairs) {
    vector<string> result;
    DirectedGeneratedParentheses(num_pairs, num_pairs, "", &result);
    return result;
}
