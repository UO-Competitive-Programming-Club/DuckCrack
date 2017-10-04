#include "../Debug.h"
using namespace std;

bool find132pattern(vector<int>& nums) {
	int s3 = INT_MIN;
	stack<int> st;

	for( int i = nums.size() - 1; i >= 0; i -- ){
		if( nums[i] < s3 )  { 
            return true;
        } else {
            while( !st.empty() && nums[i] > st.top() ){ 
                s3 = st.top(); st.pop(); 
            }
		}

		st.push(nums[i]);
	}

	return false;
}

int main() {
    vector<int> A = {1,0,1,-4,-3};
    std::cout << find132pattern(A) << std::endl;

    return 0;
}
