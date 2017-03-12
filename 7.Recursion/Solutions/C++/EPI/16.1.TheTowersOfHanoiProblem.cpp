#include "../Debug.h"

using namespace std;

const int kNumPegs = 3;

void ComputeTowerHanoiSteps(int num_rings_to_move,
                            vector<stack<int>>& pegs, int from_peg,
                            int to_peg, int use_peg) {

    if (num_rings_to_move > 0) {
        ComputeTowerHanoiSteps(num_rings_to_move - 1, pegs, from_peg, use_peg, to_peg);
        pegs[to_peg].push(pegs[from_peg].top());
        pegs[from_peg].pop();
        cout << "Move from pegs " << from_peg << " to peg " << to_peg << endl;
        ComputeTowerHanoiSteps(num_rings_to_move - 1, pegs, use_peg, to_peg, from_peg);
    }
}

void ComputeTowerHanoi(int num_rings) {
    vector<stack<int>> pegs(kNumPegs);
    for (int i = num_rings; i >= 1; --i) {
        pegs[0].push(i);
    }
    
    ComputeTowerHanoiSteps(num_rings, pegs, 0, 1, 2);
}

int main(void) {
    ComputeTowerHanoi(10);
    return 0;
}
