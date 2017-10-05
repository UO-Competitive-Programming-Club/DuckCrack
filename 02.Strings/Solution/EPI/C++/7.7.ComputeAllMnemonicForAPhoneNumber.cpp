#include "../Debug.h"
using namespace std; 

// this is an example of inefficent solution
/* void PhoneNumbersEncodeHelper(const string& phone_number, string partial_decoding, */
/*         vector<string>& result, const vector<string>& num_letters, size_t digit_idx) { */
/*     if (digit_idx == phone_number.size()) { */
/*         result.push_back(partial_decoding); */
/*     } */ 
/*     if (digit_idx < phone_number.size()){ */
/*         string letter_list = num_letters[ phone_number[digit_idx] - '0' ]; */
/*         for (auto c: letter_list) { */
/*             PhoneNumbersEncodeHelper(phone_number, partial_decoding + c, result, num_letters, digit_idx + 1); */
/*         } */
/*     } */
/* } */

void PhoneNumbersEncodeHelper(const string& phone_number, string& partial_decoding,
        vector<string>& result, const vector<string>& num_letters, size_t digit_idx) {

    if (digit_idx == phone_number.size()) {
        result.push_back(partial_decoding);
    } 
    
    if (digit_idx < phone_number.size()){
        string letter_list = num_letters[ phone_number[digit_idx] - '0' ];
        for (auto c: letter_list) {
            partial_decoding[digit_idx] = c;
            PhoneNumbersEncodeHelper(phone_number, partial_decoding, result, num_letters, digit_idx + 1);
        }
    }
}

vector<string> PhoneNumbersEncode(const string& phone_number) {
    vector<string> num_letters = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"},
                   result;

    string temp = phone_number;
    PhoneNumbersEncodeHelper(phone_number, temp, result, num_letters, 0);

    return result;
}

int main() {
    string phone_number = "123";
    std::cout << phone_number << std::endl;
    vector<string> result = PhoneNumbersEncode(phone_number);
    print_vector(result);

    return 0;
}
