
bool wordBreak(string& s, const vector<string>& wordDict) {
    if (s.empty()) return true;
    
    vector<int> memo(s.size(), false);
    
    unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    
    for (int i = 0; i < s.size(); ++i) {
        for (int substr_begin_index = i; substr_begin_index >= 0; --substr_begin_index) {
            int substr_len = i - substr_begin_index + 1; 
            string potential_word = s.substr(substr_begin_index, substr_len);
            
            bool is_word = dict.find(potential_word) != dict.end();
            bool previous_result = (substr_begin_index > 0) ? memo[substr_begin_index - 1] : true;
            
            
            
            memo[i] |= (previous_result && is_word);

        }
        
        cout << endl;

    }
    
    return memo[s.size() - 1];
}

        
      
