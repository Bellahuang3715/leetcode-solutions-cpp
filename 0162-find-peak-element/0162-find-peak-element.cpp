class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // O(logn) => binary search
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // peak is in left half
            if (nums[mid] > nums[mid+1])
            {
                right = mid;
            }
            // peak is in right half
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};