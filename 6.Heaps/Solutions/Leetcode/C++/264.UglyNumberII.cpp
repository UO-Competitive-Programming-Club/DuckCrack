#include "../Debug.h"

using namespace std;


/* this is an example of using heap which has a run time complexity of O(n * log(n)) */
int nthUglyNumberHeap(int n) {
	if (n <= 1) {
		return 1;
	}

	int divisors[3] = { 2, 3, 5 };
	priority_queue<int, vector<int>, greater<int>> min_heap;
	
	for (int j = 0; j < 3; j++) {
	   min_heap.emplace(divisors[j]);
	}
	
	for (int i = 1; i < n - 1; i++) {
	   int prev_ulgy = min_heap.top();
	   while (prev_ulgy == min_heap.top()) {
			min_heap.pop();
	   }

	   for (int j = 0; j < 3 && !min_heap.empty(); j++) {
		   int new_cannidate = prev_ulgy * divisors[j];
		   // here we have to handle multiplication overflow	
		   if ( (new_cannidate > prev_ulgy) && (new_cannidate / divisors[j] == prev_ulgy) ) {                   
			   min_heap.emplace(new_cannidate);
		   }
	   }
	}     

	return min_heap.top();
}


int nthUglyNumberDP(int n) {
    if( n <= 0 ) { return false; }       
    if( n == 1 ) { return true; }
    int t2 = 0, t3 = 0, t5 = 0; 

    vector<int> ulgy_numbers(n);

    ulgy_numbers[0] = 1;

    for( int i  = 1; i < n ; i ++ ) {
        ulgy_numbers[i] = min({ ulgy_numbers[t2] * 2, ulgy_numbers[t3] * 3, ulgy_numbers[t5] * 5 });

        if (ulgy_numbers[i] == ulgy_numbers[t2] * 2) t2++; 
        if (ulgy_numbers[i] == ulgy_numbers[t3] * 3) t3++;
        if (ulgy_numbers[i] == ulgy_numbers[t5] * 5) t5++;
    }

    return ulgy_numbers[n - 1];
}

int main(void) {
    return 0;
}


