#include "../Debug.h"

using namespace std;

void DirectedPowerSet(const vector<int>& input_set, int to_be_selected, 
        vector<int>* selected_so_far, vector<vector<int>>* power_set) {

    if (to_be_selected == (int) input_set.size()) {
        power_set->emplace_back(*selected_so_far);
    } else {
        selected_so_far->emplace_back(input_set[to_be_selected]);
        DirectedPowerSet(input_set, to_be_selected + 1, selected_so_far, power_set);
        selected_so_far->pop_back();
        DirectedPowerSet(input_set, to_be_selected + 1, selected_so_far, power_set);
    }
}

void GeneratePowerSet(vector<int>& set) {
    vector<vector<int>> result;
    DirectedPowerSet(set, 0, new vector<int>, &result);
    PrintMatrix(result);
}


int main(void) {
    vector<int> set = { 0, 1, 2 };
    GeneratePowerSet(set);
    return 0;
}
