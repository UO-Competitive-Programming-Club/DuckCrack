#include "../Debug.h"
/* the program below computes the nth row of the pascal triangle */

using namespace std;
vector<int> PascalTriangle(int k) {
    if (k < 1) { return { 1 }; }
    if (k == 2) { return { 1, 1 }; }

    vector<int> pre_layer = {1, 1},
                cur_layer;

    for (int i = 2; i < k; i++) {
        cur_layer = vector<int>(i + 1, 1);
        for (int j = 1; j < static_cast<int>(cur_layer.size()) - 1; ++j) {
            cur_layer[j] = pre_layer[j - 1] + pre_layer[j];
        }

        pre_layer = cur_layer;
    }

    return cur_layer;
}

int main() {
    vector<int> nthrow = PascalTriangle(5);

    print_vector(nthrow);

    return 0;
}
