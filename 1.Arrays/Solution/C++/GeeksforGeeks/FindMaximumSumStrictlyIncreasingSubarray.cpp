#include "../Debug.h"
using namespace std;
int maxsum_SIS(vector<int> arr) {
    // Initialize max_sum be 0
    int max_sum = 0, n = arr.size();
 
    // Initialize current sum be arr[0]
    int current_sum = arr[0] ;
 
    // Traverse array elements after first element.
    for (int i = 1; i < n ; i++ ) {
        // update current_sum for strictly increasing subarray
        if (arr[i-1] < arr[i]) {
            current_sum = current_sum + arr[i];
        } else { 
            // update max_sum and current_sum ;
            max_sum = max(max_sum, current_sum);
            current_sum = arr[i];
        }
    }
 
    return max(max_sum, current_sum);
}
