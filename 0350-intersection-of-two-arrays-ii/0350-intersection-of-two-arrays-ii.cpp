class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> result;
        for (auto num : nums1) {
            map[num]++;
        }
        for (auto num : nums2) {
            if (map[num] > 0) {
                result.push_back(num);
                map[num]--;
            }
        }
        return result;
    }
};