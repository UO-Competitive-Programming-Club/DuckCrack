
bool increasingTriplet(vector<int>& nums) {
    int nlen = nums.size();
    if (nlen < 3) {

		return false;
    }
    
    int smallest = nums[0];
    int mid = INT_MAX;

    for (int i = 1; i < nlen; ++i) {
        if (nums[i] > mid) {
            return true;
        }
        
        smallest = min(smallest, nums[i]);
        if (nums[i] > smallest) {
            mid = min(mid, nums[i]);
        }
        
    }
    
    return false;
}
