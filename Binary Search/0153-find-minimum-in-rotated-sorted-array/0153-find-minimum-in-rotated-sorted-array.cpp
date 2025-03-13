class Solution {
public:
    int findMin(vector<int>& nums) {
        // variant of binary search
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right)
        {
            // int mid = low + (high - low) / 2;  to avoid overflow
            int mid = (left + right) / 2;
            
            // mid -> right is UNSORTED
            // thus, the min MUST be somewhere from mid -> right
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            // left -> mid is UNSORTED
            // thus, the min MUST be somewhere between left -> mid
            else
            {
                right = mid;
            }
        }
        return nums[left];
    }
};