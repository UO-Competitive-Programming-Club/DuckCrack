#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool canCross(vector<int>& stones) {
    int slen = stones.size();
    unordered_map<int, unordered_set<int> > stone_jump_map;

    stone_jump_map[0] = unordered_set<int>();
    stone_jump_map[1] = { 1 };

    for (int i = 0; i < slen; ++i) {
        if (i > 1) stone_jump_map[stones[i]] = { };
        for (int j = i - 1; j > 0; --j) {
            int pstone = stones[j], cstone = stones[i],
                k = cstone - pstone;

            auto & jumps_to_cur_stone = stone_jump_map[cstone];
            auto & jumps_to_previous_stone = stone_jump_map[pstone];

            if (jumps_to_previous_stone.find(k - 1) != jumps_to_previous_stone.end()) {
                jumps_to_cur_stone.insert(k);
            } else if (jumps_to_previous_stone.find(k) != jumps_to_previous_stone.end()) {
                jumps_to_cur_stone.insert(k);
            } else if (jumps_to_previous_stone.find(k + 1) != jumps_to_cur_stone.end()) {
                jumps_to_cur_stone.insert(k);
            }
        }
    }

    return !stone_jump_map[stones.back()].empty();
}
