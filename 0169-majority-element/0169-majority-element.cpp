class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> numsCount;
        for (auto num: nums) {
            numsCount[num]++;
        }
        for (auto ele: numsCount) {
            if (ele.second > len/2) {
                return ele.first;
            }
        }
        return NULL;
    }
};