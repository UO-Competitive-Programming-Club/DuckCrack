#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int findLongestChain(vector<vector<int> >& pairs) {
    int plen = pairs.size();
    vector<int> memo(plen, 1);
    
    sort(pairs.begin(), pairs.end(), [](vector<int>& pa, vector<int>& pb){
        return pa.front() < pb.front();
    });
    
    for (int i = 1; i < plen; ++i) {
        for (int j = 0; j < i; ++j) {
            int a = pairs[j][0],
                b = pairs[j][1],
                c = pairs[i][0],
                d = pairs[i][1];
            
            if (b < c) {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
    }
    
    return memo[plen - 1];

}
