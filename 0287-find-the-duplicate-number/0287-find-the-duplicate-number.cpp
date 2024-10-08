class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        // Step 2: Move slow one step and fast two steps until they meet
        do {
            slow = nums[slow];         // slow moves one step
            fast = nums[nums[fast]];   // fast moves two steps
        } while (slow != fast);
        
        // Step 3: Reset one pointer to the start
        slow = nums[0];
        
        // Step 4: Move both pointers one step at a time until they meet at the duplicate
        while (slow != fast) {
            slow = nums[slow];  // Both pointers move one step
            fast = nums[fast];
        }
        
        // Step 5: The point where they meet is the duplicate number
        return slow;
    }
};