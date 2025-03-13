class Solution {
public:
    int findFirst(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int position = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                position = mid;
                right = mid - 1;    // continue searching left to find FIRST occurrence
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return position;
    }
    
    int findLast(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int position = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                position = mid;
                left = mid + 1;    // continue searching left to find FIRST occurrence
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return position;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        // O(logn) => binary search
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
            return {first, last};
    }
};