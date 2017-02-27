#include "../Debug.h"

using namespace std;

vector<double> MedianOfOnlineData(const vector<double>& data) {
    priority_queue<double, vector<double>, less<double>> max_heap;
    priority_queue<double, vector<double>, greater<double>> min_heap;

    vector<double>::const_iterator iter = data.cbegin();
    vector<double>::const_iterator end  = data.cend();
    vector<double> result;

    double median = numeric_limits<double>::min();

    /* using a while loop to simulate the data stream */
    while (iter != end) {
        double cur_val = *iter;

        (cur_val > median) ? 
            min_heap.emplace(cur_val) : max_heap.emplace(cur_val);

        int min_heap_size = min_heap.size(),
            max_heap_size = max_heap.size();

        /* when one heap has two more element than the other heap, we move the element over 
         * and the size of two heaps will be balanced */

        if (min_heap_size - max_heap_size >= 2) {
            max_heap.emplace(min_heap.top());
            min_heap.pop();

        } else if (max_heap_size - min_heap_size >= 2) { 
            min_heap.emplace(max_heap.top());
            max_heap.pop();
        } 

        /* at this point we are sure that the size of two heaps are balanced */ 
        if ((min_heap_size +  max_heap_size) % 2) {
            median = (max_heap_size > min_heap_size) ? 
                max_heap.top() : min_heap.top();
        } else {
            median = (min_heap.top() + max_heap.top()) / 2;
        }

        result.emplace_back(median);
        iter = next(iter);
    }

    return result;
}

int main(void)  {

    vector<double> input = {
        1, 0, 3, 5, 2, 0, 1
    };

    PrintVector(MedianOfOnlineData(input));

    return 0;
}
