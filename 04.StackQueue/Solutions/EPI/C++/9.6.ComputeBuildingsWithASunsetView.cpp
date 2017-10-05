#include "../Debug.h"
using namespace std;

vector<int> SunsetView(vector<int> & houses) {
    struct HeightID {
        int height, id;
    };

    int hlen = houses.size();
    vector<int> result;
    stack<HeightID> house_stack;

    if (houses.empty()) { return result; }

    house_stack.emplace(HeightID{ houses.back(), hlen - 1 });

    for (int i = hlen - 2; i >= 0; --i) {

        while (!house_stack.empty() && houses[i] >= house_stack.top().height) {
            house_stack.pop();
        }

        house_stack.emplace(HeightID{ houses[i], i });
    }

    while (!house_stack.empty()) {
        result.emplace_back(house_stack.top().id);
        house_stack.pop();
    }

    return result;
}

int main() {
    vector<int> houses = {9,8,7,6,5,4,3,2,1};
    PrintVector(SunsetView(houses));

    return 0;
}
