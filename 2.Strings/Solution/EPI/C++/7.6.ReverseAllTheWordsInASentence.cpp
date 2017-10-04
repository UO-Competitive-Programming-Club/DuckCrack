#include "../Debug.h"
using namespace std;
    
void ReverseWordsInSentence(string& s) {
    reverse(s.begin(), s.end());
    size_t begin = 0, end = 0, slen = s.size();
    while ( begin < slen) {
        end = s.find(' ', begin);

        int end_offset = 0;
        if (end == string::npos) {
            end = slen - 1;
            end_offset = 1;
        } 

        reverse(s.begin() + begin, s.begin() + end + end_offset);
        begin = end + 1;
    }
}

int main() {
    string s = "the sky is blue";
    ReverseWordsInSentence(s);
    std::cout << s << std::endl;
    return 0;
}

