class Solution {
public:
    int search(vector<int>& nums, int target) {
        // variant of binary search
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            // everything to the left of mid is sorted
            else if (nums[mid] >= nums[left])
            {
                // target is between left and mid
                if (nums[left] <= target && target <= nums[mid])
                {
                    right = mid - 1;
                }
                // target is to the right of mid
                else
                {
                    left = mid + 1;
                }
            }
            // everything to the right of mid is sorted
            else
            {
                // target is between mid and right
                if (nums[mid] <= target && target <= nums[right])
                {
                    left = mid + 1;
                }
                // target is to the left of mid
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};