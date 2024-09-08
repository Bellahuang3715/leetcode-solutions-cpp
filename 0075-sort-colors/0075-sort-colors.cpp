class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, cur = 0, high = nums.size() - 1;
        
        while (cur <= high)
        {
            if (nums[cur] == 0)
            {
                swap(nums[low], nums[cur]);
                low++;
                cur++;
            }
            else if (nums[cur] == 1)
            {
                cur++;
            }
            else    // nums[cur] == 2
            {
                swap(nums[cur], nums[high]);
                high--;
            }
        }
    }
};