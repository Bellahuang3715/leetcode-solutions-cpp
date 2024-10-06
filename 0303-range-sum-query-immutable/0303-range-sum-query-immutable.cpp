class NumArray {
public:
    vector<int>& preSum; // `preSum` will reference to `nums` array, no copy at all!
    
    // preSum(nums) is the initializer list of the constructor
    // (initializes member variable preSum using the value of nums)
    NumArray(vector<int>& nums) : preSum(nums) {    
        for (int i = 1; i < preSum.size(); ++i)
            preSum[i] += preSum[i-1]; 
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return preSum[right];
        return preSum[right] - preSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */