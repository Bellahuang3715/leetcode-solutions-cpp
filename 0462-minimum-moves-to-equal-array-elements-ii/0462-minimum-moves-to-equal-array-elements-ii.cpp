class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int middle = len/2;
        int moves = 0;
        for (int i = 0; i < len; i++) {
            moves += abs(nums[middle] - nums[i]);
        }
        return moves;
    }
};
