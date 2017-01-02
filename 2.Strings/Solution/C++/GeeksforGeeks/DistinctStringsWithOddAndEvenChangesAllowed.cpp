#include "../Debug.h"
using namespace std;

string GenerateEncodingString(const string& s) {
    int alphabet_size = 256;
    vector<int> even_count(alphabet_size, 0),
                odd_count(alphabet_size, 0);

    for (size_t i = 0; i < s.size(); i++) {
        (i % 2 == 0) ? ++even_count[s[i]] : ++odd_count[s[i]];
    }

    string encoded_string;
    for (int i = 0; i < alphabet_size; i++) {
        if (even_count[i] == 0 && odd_count[i] == 0) {
            continue;
        } else {
            if (even_count[i] > 0) {
                encoded_string += ((char) i) + (even_count[i] - '0');
            }

            if (odd_count[i] > 0) {
                encoded_string += ((char) i) + (odd_count[i] - '0');
            }
        }
    }

    return encoded_string; 
}

int CountDistinct(vector<string>& strings) {
    unordered_set<string> distinct_set;
    for (auto s: strings) {
        distinct_set.insert(GenerateEncodingString(s));
    }

    return strings.size() - distinct_set.size();
}

int main() {
    vector<string> V = {"abc", "cba"}; //{"abcd", "cbad", "bacd"};
    std::cout << CountDistinct(V) << std::endl;
    return 0;
}
