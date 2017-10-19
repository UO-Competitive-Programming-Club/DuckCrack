#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>

using namespace std;

// time limit exceeded
int findSubstringInWraproundString_BAD(string p) {
    int plen = p.size();
    if (plen == 0) return 0;
    unordered_set<string> substr_set;

    for (int i = 0; i < plen; ++i) {
        string sstr = p.substr(i, 1);
        if (substr_set.find(sstr) == substr_set.end()) {
            substr_set.insert(sstr);
        }
    }

    for (int l = 2; l <= plen; ++l) {
        for (int begin = 0; begin < plen - l + 1; ++begin) {
            int end = begin + l - 1;
            string sstr = p.substr(begin, l);
                            
            if (substr_set.find(sstr) == substr_set.end()) {
                string prev_substr = sstr.substr(0, sstr.size() - 1);
                int prev_end = p[end - 1] - '0', cur_end = p[end] - '0',
                    diff = cur_end - prev_end;

                if ((diff == 1 || diff == -25) && (substr_set.find(prev_substr) != substr_set.end())) {                       
                    substr_set.insert(sstr);
                }
            }
        }
    }
    
    return substr_set.size();
}



// this is optimized solution  
int findSubstringInWraproundString(string p) {
    int plen = p.size();

    if (plen <= 1) { return plen; }

    vector<int> memo(26, 0);

    int start = 0;
    memo[p[start] - '0'] = 1;

    for (int j = 1; j < plen; ++j) {
        memo[p[j] - '0'] = max(p[j] - '0', 1);

        int prev_end = p[j - 1] - '0', cur_end = p[j] - '0',
            diff = cur_end - prev_end;

        if (!(diff = -25 || diff == 1)) {
            memo[j] = max(memo[j], j - start);
            start = j;
        }
    }

    return accumulate(memo.begin(), memo.end(), 0);
}
