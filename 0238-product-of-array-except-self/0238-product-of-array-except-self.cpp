/*
238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

*/

class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int left = 1, right = 1;
        for (int i = 0; i < n; i++) {
            result[i] *= left;
            result[n - 1 - i] *= right;
            left *= nums[i];
            right *= nums[n - 1 - i];
        }
        return result;
    }
}


class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> answer(n, 1);
            
            // Compute products of all elements to the left of each index.
            for (int i = 1; i < n; i++) {
                answer[i] = answer[i - 1] * nums[i - 1];
            }
            
            // R will hold the product of all elements to the right.
            int R = 1;
            for (int i = n - 1; i >= 0; i--) {
                answer[i] *= R;
                R *= nums[i];
            }
            
            return answer;
        }
    };