#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    struct State { string word; int depth; };

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> not_visited(wordList.begin(), wordList.end());

        /* since we assume that every word has the same length */
        /* vector<unordered_set<char>> replace_chars(beginWord.size(), unordered_set<char>()); */
        queue<State> frontier; frontier.push({ beginWord, 1 });

        while (!frontier.empty()) {
            /* mark the current node as visited */
            State cs = frontier.front(); frontier.pop(); not_visited.erase(cs.word);
            /* when we find the goal state */
            if (cs.word == endWord) return cs.depth;

            /* expand the search tree */
            vector<State> next_states = nextStates(cs, not_visited);
            for (State& s: next_states) frontier.push(s);
        }

        return 0;
    }

    vector<State> nextStates(State cur_state, unordered_set<string>& not_visited) {
        string word = cur_state.word; int wlen = word.size();
        vector<State> result;

        for (int i = 0; i < wlen; ++i) {
            /* get the orginal character */
            char old_char = word[i];
			/* try every character */
            for (int j = 0; j < 26; ++j) {
                word[i] = 'a' + j;
                auto it = not_visited.find(word);
                if (it != not_visited.end()) result.push_back({ *it, cur_state.depth + 1 });
            }

            word[i] = old_char;
        }

        return result;
    }
};
