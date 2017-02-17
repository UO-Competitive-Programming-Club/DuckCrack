#include "../Debug.h"
using namespace std;

void permuteHelper(string s, size_t begin_index) {
   size_t i; 
   if (begin_index == s.size() - 1) {
     std::cout << s << std::endl;
   } else {
       for (i = begin_index; i < s.size(); i++) {
          swap(s[begin_index], s[i]);
          permuteHelper(s, begin_index + 1);
          /* swap(s[begin_index], s[i]); */ 
       }
   }
}

void permute(string s) {
    permuteHelper(s, 0);
}

int main() {
    string s = "1234";
    permute(s);
    return 0;
}
