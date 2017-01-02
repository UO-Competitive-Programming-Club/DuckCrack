#include "../Debug.h"

using namespace std;

int lengthOfLongestSubstring(const string& s) {
    vector<int> prev_occur(256, -1);

    int slen = s.size(), 
        max_length = 0, 
        longest_ends_at_previous = 0; // this varible keeps track of the longest qulified substring that ends 
                                      // at the previous location

    for (int i = 0; i < slen; i++) {
        int longest_ends_at_here = min(longest_ends_at_previous + 1, i - prev_occur[s[i]]);
        max_length = max(max_length, longest_ends_at_here);
        longest_ends_at_previous = longest_ends_at_here;
        prev_occur[s[i]] = i;
    }

    return max_length;
}
