#include "../Debug.h"

using namespace std;

int ReplaceAndRemove(char s[], int size)  {
    /* first delete all the entries has d */ 
    int wr_idx = 0, num_a = 0;
    for (int i = 0; i < size; i++) {
        if (s[i] != 'b') {
            swap(s[wr_idx++], s[i]);
        }

        if (s[i] == 'a') {
            ++num_a;
        }
    }

    /* index of the end of valid characters */
    int cur_idx = wr_idx - 1;

    /* the end of valid array after inserting b's */
    wr_idx = wr_idx + num_a - 1;
    int final_size = wr_idx + 1;

    /* basically this rewrites the array, based on the current index instead of */
    /* allocating a new array */
    for ( ; cur_idx >= 0 && wr_idx >= 0; --cur_idx ) {
        if (s[cur_idx] == 'a') {
            s[wr_idx--] = 'd';
            s[wr_idx--] = 'd';
        } else {
            s[wr_idx--] = s[cur_idx];
        }
    }
    
    return final_size;
}

int main() {
    char s[] = "aXaXaXaXaXaXbbbbbbbbbb---------------------------------------------------------------------------------------";
    std::cout << s << std::endl;
    ReplaceAndRemove(s, 10);

    std::cout << s << std::endl;
    return 0;
}
