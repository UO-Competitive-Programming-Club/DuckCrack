#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    struct state { string board; int balls_used; };

    int findMinStep(string board, string hand) {
        int min_ball = INT_MAX, hlen = hand.size();
        /* initialze the search space */
        stack<state> frontier; frontier.push({ board, 1 });
        while (!frontier.empty()) {
            /* visit the current node */
            state cs = frontier.top(); frontier.pop();
            /* we found a goal state */
            if (cs.board.empty()) min_ball = min(min_ball, cs.balls_used);
            /* add the next states to the stack */
            vector<state> nss = nextStates(cs, hand);
            for (state ns: nss) frontier.push(ns);
        }

        return (min_ball == INT_MAX) ? -1 : min_ball;
    }

    vector<state> nextStates(state cs, string hand) {
        vector<state> res;
        if (cs.balls_used == 0 || cs.board.empty()) return res;

        int hlen = hand.size(), blen = cs.board.size();

        for (int i = 0; i <= blen; i++) {
            int ball_idx = cs.balls_used - 1;
            string nboard = insert(cs.board, hand[ball_idx], i);
            res.push_back({ nboard, cs.balls_used - 1 });
        }

        return res;
    }

    string insert(string board, char ball, int position) {
        string nboard;
        return nboard;
    }
};
