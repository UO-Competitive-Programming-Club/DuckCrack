#include "../Debug.h"
using namespace std; 

void PhoneNumbersEncodeHelper(const string& phone_number, string partial_decoding,
        vector<string>& result, const vector<string>& num_letters, size_t digit_idx) {

    if (digit_idx == phone_number.size()) {
        result.push_back(partial_decoding);
    } 
    
    if (digit_idx < phone_number.size()){
        string letter_list = num_letters[ phone_number[digit_idx] - '0' ];
        for (auto c: letter_list) {
            PhoneNumbersEncodeHelper(phone_number, partial_decoding + c, result, num_letters, digit_idx + 1);
        }
    }
}

vector<string> PhoneNumbersEncode(const string& phone_number) {
    vector<string> num_letters = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"},
                   result;

    PhoneNumbersEncodeHelper(phone_number, "", result, num_letters, 0);

    return result;
}

int main() {
    string phone_number = "2276696";
    std::cout << phone_number << std::endl;
    vector<string> result = PhoneNumbersEncode(phone_number);
    print_vector(result);

    return 0;
}
