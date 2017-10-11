#include <iostream>
#include <vector>

using namespace std;

int eggDrop(int egg_num, int floor_num) {
    vector<vector<int> > memo(egg_num + 1, vector<int>(floor_num + 1, INT_MAX));

    for (int i = 0; i <= floor_num; i++) {
        memo[0][i] = i;
    }

    for (int j = 1; j <= egg_num; j++) {
        memo[j][0] = 0;
        memo[j][1] = 1;
    }

    for (int cur_egg = 1; cur_egg <= egg_num; ++cur_egg) {
        for (int cur_floor = 1; cur_floor <= floor_num; ++cur_floor) {
            for (int cur_throw_floor = 0; cur_throw_floor <= cur_floor; ++cur_throw_floor) {
                int attempts_when_egg_break = memo[cur_egg - 1][cur_throw_floor - 1] + 1;
                int attempts_when_egg_intact = memo[cur_egg][floor_num - cur_throw_floor] + 1;
                memo[cur_egg][cur_floor] = min(memo[cur_egg][cur_floor], max(attempts_when_egg_break, attempts_when_egg_intact));
            }
        }
    }

    return memo[egg_num][floor_num];
}
