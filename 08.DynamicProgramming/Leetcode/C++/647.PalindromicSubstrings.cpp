#include <iostream>
#include <vector>

using namespace std;

int countSubstrings(string s) {
    int slen = s.size(), result = 0;
	vector<vector<int> > memo(slen, vector<int>(slen, 0));

    for (int l = 1; l <= slen; ++l) {
        for (int begin = 0; begin < slen - l + 1; ++begin) {
            int end = begin + l - 1;
            if (s[begin] == s[end]) {

                memo[begin][end] = (end - begin <= 1) ? 
                                        1 : (memo[begin + 1][end - 1] == 1) ? 
                                                1 : 0;
                result += memo[begin][end];
            }
        }
    }

    return result;
}
