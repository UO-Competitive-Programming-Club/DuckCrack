class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s.front() == '0') return 0;
        
        int slen = s.size();
        vector<int> memo(slen + 1, 1);
        
        for (int l = 2; l <= slen; ++l) {
            if (s[l - 2] == '0' && s[l - 1] == '0') return 0;
            
            string prev_two = s.substr(l - 2, 2);
            memo[l] = ((s[l - 1] != '0') ? memo[l - 1] : 0) + (canBeDecoded(prev_two) ? memo[l - 2] : 0);
        }
        
        return memo[slen];
    }
    
    int canBeDecoded(string s) {
        int si = stoi(s);
        return s.front() != '0' && (1 <= si && si <= 26);
    }
};
