class Solution {
public:
    // Kadane's Algorithm - find the maximum sum of a contiguous subarray in an array with a runtime of O(n)

    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // continue adding the current element to the existing subarray, OR
            // start a new subarray with the current element (if adding it to the existing subarray would make the sum less than just starting with the current element)
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};