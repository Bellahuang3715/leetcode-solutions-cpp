class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // two pointers, one starting at index 0 one at end index
        int left = 0;
        int right = numbers.size() - 1;
        // add numbers
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                return {left+1, right+1};
            }
            // if too big, advance right pointer
            else if (sum > target)
            {
                right--;
            }
            // else if too small, advance left pointer
            else
            {
                left++;
            }
        }
        return {};
        
    }
};