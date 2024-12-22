class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestSeq = 0;
        
        for (int num : numSet)
        {
            // check if num is the start of a sequence
            if (numSet.find(num-1) == numSet.end())
            {
                int currentNum = num;
                int currentStreak = 1;
                
                // count length of sequence
                while (numSet.find(currentNum+1) != numSet.end())
                {
                    currentNum++;
                    currentStreak++;
                }
                longestSeq = max(currentStreak, longestSeq);
            }
        }
        return longestSeq;
    }
};