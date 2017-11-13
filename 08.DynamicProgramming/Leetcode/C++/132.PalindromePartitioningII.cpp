/* TLE */
class Solution {
public:
    int minCutBad(string s) {
        if (s.empty()) return 0;
        
        int slen = s.size();
        vector<vector<int>> memo(slen, vector<int>(slen, INT_MAX));
        
        for (int l = 1; l <= slen; ++l) {
            for (int begin = 0; begin <= slen - l; ++begin) {
                int end = begin + l - 1;
                
                /* situation where the length is one */
                if (begin == end) {
                    memo[begin][end] = 0;
                    continue;
                }
                
                /* situation where inside is a palidrom */
                if (s[begin] == s[end] && 
                    (end - begin == 1 || memo[begin + 1][end - 1] == 0)) {
                    memo[begin][end] = 0;
                    continue;
                }
                
                for (int k = begin; k < end; ++k) {
                    memo[begin][end] = min(memo[begin][end], memo[begin][k] + memo[k + 1][end] + 1);  
                }
            }            
        }
        
        return memo[0][slen - 1];
    }
};
