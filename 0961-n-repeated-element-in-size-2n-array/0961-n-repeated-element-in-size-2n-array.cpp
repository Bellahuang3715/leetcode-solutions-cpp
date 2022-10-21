class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int times = nums.size()/2;
        int result = 0;
        unordered_map<int, int> map;
        for (auto num : nums) {
            map[num]++;
        }
        for (auto &it : map) {
            if (it.second == times) {
                result = it.first;
            }
        }
        return result;
    }
};