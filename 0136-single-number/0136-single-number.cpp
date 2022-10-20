class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> numCount;
        for (auto num: nums) {
            numCount[num]++;
        }
        for (auto ele: numCount) {
            if (ele.second == 1) {
                return ele.first;
            }
        }
        return -1;
    }
};