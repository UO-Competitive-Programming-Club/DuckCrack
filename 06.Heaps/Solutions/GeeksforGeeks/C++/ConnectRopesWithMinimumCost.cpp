#include "../Debug.h"

using namespace std;
int minCost(vector<int>, int n) {
    int cost = 0;  
 
    priority_queue<int, vector<int>, greater<int>> min_heap;
 
    while (!min_heap.empty()) {

        int first_min     = min_heap.top(); min_heap.pop();
        int second_min    = min_heap.top(); min_heap.pop();
 
        cost += (first_min + second_min);  // Update total cost
 
        min_heap.emplace(first_min + second_min);
    }
 
    return cost;
}
