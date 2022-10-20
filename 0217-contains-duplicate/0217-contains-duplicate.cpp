class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> occurrences;
        for (auto num: nums) {
            occurrences[num]++;
        }
        for (auto ele: occurrences) {
            if (ele.second > 1) {
                return true;
            }
        }
        return false;
    }
};

